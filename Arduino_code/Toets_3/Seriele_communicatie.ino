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
  if (input == "TEMPERATURE_C" || input == "TEMPERATURE_F" || input == "HUMIDITY") {
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

<<<<<<< HEAD
void PrintValuesToSerialPort(float value, String type){
  Serial.print(type);
  Serial.print(": ");
  Serial.println(value);
=======
void PrintValuesToSerialPort(float value, String type) {
  if (previousValue != value) {
    Serial.print(type);
    Serial.print(": ");
    Serial.println(value);
  }
  previousValue = value;
}

void PrintUnitToSerialPort(String unit){
  Serial.print("UNIT: ");
  Serial.println(unit);
>>>>>>> d1098a89dfc66a9f09d5bb8aa3b5db2126b216bb
}
