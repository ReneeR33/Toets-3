String BuildMessage() {
  String message = "";
  bool startReceived = false;
  while (true) {
    char startChar = '#';
    char stopChar = '%';
    int incomingByte = 0;


    incomingByte = Serial.read();
    char receivedCharacter = (char) incomingByte;

    if (receivedCharacter == '%') {
      startReceived = false;
      return message;
    }

    if (startReceived) {
      message += receivedCharacter;
    }

    if (receivedCharacter == '#') {
      startReceived = true;
    }
  }
}

bool IsValidMessage(String input) {
  if (input == "TEMPERATURE" || input == "HUMIDITY" || input == "CELSIUS" || input == "FAHRENHEIT") {
    return true;
  }
  else {
    return false;
  }
}

bool IsSerialDataIncoming() {
  if (Serial.available() > 0) {
    return true;
  }
  else {
    return false;
  }
}

String ChangeMode(String currentMode) {
  String message;

  if (IsSerialDataIncoming()) {
    message = BuildMessage();
    if (IsValidMessage(message)) {
      Serial.println(message);
      return message;
    }
  }
  else
  {
    return currentMode;
  }
}

void PrintValuesToSerialPort(float value, String type){
  Serial.print(type);
  Serial.print(": ");
  Serial.println(value);
}

void PrintUnitToSerialPort(String unit){
  Serial.print("UNIT: ");
  Serial.println(unit);
}
