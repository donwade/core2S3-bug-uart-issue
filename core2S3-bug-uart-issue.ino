void setup() 
{
  delay(5000);
  //pinMode(18,INPUT);    // does NOT remove USB-JTAG pulses from GPIO-18 
  pinMode(19,INPUT); // DOES remove USB-JTAG pulses from BOTH GPIO-18 & GPIO-19    

  Serial.printf("USB CDC on Boot=ENABLED\n");
  Serial.printf("USB CORE DEBUG LEVEL = verbose");
  Serial.printf("Erase all flash before download = TRUE");
  Serial.printf("USB MODE = USB-OTG");
  Serial.printf("UPLOAD MODE = USB-OTG");


}

int i = 0;

void loop() {
  // Check if there is any data available to be read from the serial port.
  if (Serial.available() > 0) {
    // Read the incoming byte (character) from the serial buffer.
    int incomingByte = Serial.read(); 

    // Print the received byte back to the serial monitor.
    // Serial.write() is generally preferred for sending raw bytes.
    Serial.printf("thank you for your input of %c\n", incomingByte); 
  }
  else
  {
    Serial.printf("gimme keyboard input %d\n", i++);
    delay(1000);
  
  }
}
