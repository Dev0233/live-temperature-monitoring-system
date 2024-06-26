**Live Temperature Monitoring System README**

**Introduction:**
This README provides an overview of the Live Temperature Monitoring System, which allows users to monitor real-time temperature readings and log them into an Excel sheet with timestamps. The system is designed to be simple to set up and use, making it suitable for various applications where temperature monitoring is crucial.

**Hardware Requirements:**
1. Arduino board (e.g., Arduino Uno, Arduino Nano)
2. Temperature sensor (e.g., DS18B20, DHT11, DHT22)
3. Push button
4. Connecting wires
5. Computer with USB port
6. Excel software (MS Excel, LibreOffice Calc, Google Sheets)

**Software Requirements:**
1. Arduino IDE (Integrated Development Environment)
2. Serial communication software (e.g., PuTTY, Arduino Serial Monitor)
3. Python (for optional data processing)
4. Trigger library (provided in the GitHub repository)

**Setup Instructions:**

1. **Connect the Hardware:**
   - Connect the temperature sensor to the Arduino board following the sensor's datasheet.
   - Connect the push button to the Arduino board. One end of the button should be connected to a digital pin (e.g., pin 2), and the other end should be connected to the ground.

2. **Install Arduino IDE:**
   - Download and install the Arduino IDE from the official Arduino website (https://www.arduino.cc/en/software).
   - Connect the Arduino board to your computer using a USB cable.

3. **Upload Arduino Sketch:**
   - Open the Arduino IDE.
   - Copy and paste the provided Arduino sketch (`.ino` file) into the IDE.
   - Verify and upload the sketch to the Arduino board.

4. **Install Trigger Library:**
   - Download the Trigger library ZIP file from the GitHub repository.
   - In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library.
   - Select the downloaded Trigger library ZIP file and click "Open".

5. **Prepare Excel Sheet:**
   - Create a new Excel sheet to store the temperature data.
   - Label the columns appropriately (e.g., "Date", "Time", "Temperature").
   - Save the Excel sheet in a known directory.

6. **Run Serial Monitor:**
   - Open the Arduino IDE and navigate to Tools > Serial Monitor.
   - Set the baud rate to match the value specified in the Arduino sketch.
   - You should see real-time temperature readings in the Serial Monitor window.

7. **Push Button Operation:**
   - Press the push button to trigger the sending of temperature readings to the connected Excel sheet.
   - Each time the button is pressed, a new row with the current date, time, and temperature reading will be added to the Excel sheet.

**Optional Data Processing:**

If you wish to process the temperature data further, you can use Python scripts to read the serial data from the Arduino and manipulate it as needed. This step is optional and depends on your specific requirements.

**Troubleshooting:**

- Ensure all hardware connections are secure and correct.
- Check the baud rate settings in both the Arduino sketch and the Serial Monitor.
- Verify that the Arduino board is recognized by your computer and correctly selected in the Arduino IDE.

**Conclusion:**

The Live Temperature Monitoring System provides a simple yet effective solution for monitoring temperature data in real-time and logging it into an Excel sheet. By following the setup instructions provided, you can quickly deploy this system for various applications requiring temperature monitoring. For additional functionalities and customization, refer to the Trigger library documentation provided in the GitHub repository.
