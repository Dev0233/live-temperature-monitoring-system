#include "TRIGGER_WIFI.h"
#include "TRIGGER_GOOGLESHEETS.h"
#include <DHT.h> // Include the DHT library
#include <StackThunk.h>

#define DHTPIN D5          // Pin where the DHT11 is connected
#define DHTTYPE DHT11      // DHT 11
#define _stackSize (6748/4) 


DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor

const int buttonPin = D1;  // Pin where the push button is connected
bool buttonState = false;  // Variable to store the current state of the button
bool lastButtonState = false; // Variable to store the previous state of the button

char column_name_in_sheets[][24] = {"Temperature", "Humidity"};
String Sheets_GAS_ID = "###############################################";
int No_of_Parameters = 2;

void setup() {
  Serial.begin(9600);
  Serial.println("Setup started...");
  WIFI_Connect("PSIT", "PSIT1234");
  Serial.println("Wi-Fi connected...");
  Google_Sheets_Init(column_name_in_sheets, Sheets_GAS_ID, No_of_Parameters);
  Serial.println("Google Sheets initialized...");
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as input with internal pull-up resistor
  Serial.println("Setup completed...");
  dht.begin();  // Start DHT sensor
}

void loop() {
  Serial.println("Loop iteration started...");
  // Read the state of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button state has changed (pressed)
  if (buttonState != lastButtonState && buttonState == LOW) {
    Serial.println("Button pressed...");
    // Button has been pressed, send data to Google Sheets
    float temperature = dht.readTemperature();  // Read temperature from DHT sensor
    float humidity = dht.readHumidity();  // Read humidity from DHT sensor
    if (!isnan(temperature) && !isnan(humidity)) {
      Data_to_Sheets(No_of_Parameters, temperature, humidity); // Send temperature and humidity to Google Sheets
      Serial.println("Data sent to Google Sheets.");
      Serial.printf("BSSL stack: %d\n", stack_thunk_get_max_usage());
      Serial.println(temperature);
      Serial.println(humidity);
    } else {
      Serial.println("Failed to read from DHT sensor!");
    }
  }

  // Update the last button state
  lastButtonState = buttonState;
  Serial.println("Loop iteration completed...");
  delay(2000); // Add a short delay to prevent overwhelming the serial monitor
}
