String BuildMessage() {
  String message = "";
  bool startReceived = false;
  while (true) {
    Serial.println("serial while");
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
  if (input == "TEMPERATURE" || input == "HUMIDITY") {
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
