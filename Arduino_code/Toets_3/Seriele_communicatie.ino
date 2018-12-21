String BuildMessage() {
  String message = "";
  Serial.begin(9600);
  bool startReceived = false;
  while (true) {

    char startChar = '#';
    char stopChar = '%';
    int incomingByte = 0;


    if (Serial.available() > 0) {
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
}
