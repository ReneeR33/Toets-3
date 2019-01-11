float previousValue;

//constructs a message from the Serial port
String BuildMessage() {
  String message = "";
  bool startReceived = false;
  while (true) {
    char startChar = '#';
    char stopChar = '%';
    int incomingByte = 0;


    incomingByte = Serial.read();
    char receivedCharacter = (char) incomingByte;

    //the if statements are in this order to make sure the '#' and '%' are not added to the string
    //checks if the end of the message has been send
    if (receivedCharacter == '%') {
      startReceived = false;
      return message;
    }

    //adds character to string if the start sign has been received
    if (startReceived) {
      message += receivedCharacter;
    }
    //checks if the starting character has been received
    if (receivedCharacter == '#') {
      startReceived = true;
    }
  }
}

//checks if a message is a valid command
bool IsValidMessage(String input) {
  if (input == "TEMPERATURE_C" || input == "TEMPERATURE_F" || input == "HUMIDITY") {
    return true;
  }
  else {
    return false;
  }
}

//checks if data is incoming from the PC
bool IsSerialDataIncoming() {
  if (Serial.available() > 0) {
    return true;
  }
  else {
    return false;
  }
}

//updates the command if a new command comes in
String ChangeMode(String currentMode) {
  String message;
  
  if (IsSerialDataIncoming()) {
    message = BuildMessage();
    if (IsValidMessage(message)) {
      return message;
    }
  }
  else
  {
    //returns the current mode if the mode is unchanged
    return currentMode;
  }
}

//print the measured values to the serial monitor
void PrintValuesToSerialPort(float value, String type) {
  //checks if the the incoming value has changed
  if (previousValue != value) {
    Serial.print(type);
    Serial.print(": ");
    Serial.println(value);
  }
  previousValue = value;
}
