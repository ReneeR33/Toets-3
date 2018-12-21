String message = "";

void CheckForCommunication() {
  Serial.begin(9600);
  char startChar = "#";
  char stopChar = "%";
  int incomingByte = 0;
  bool startReceived = false;
  Serial.println("check comms");

  if (Serial.available() > 0) {
    Serial.println("x Received");
    incomingByte = Serial.read();
    char receivedCharacter = (char) incomingByte;

    if (receivedCharacter == "%") {
      startReceived = false;
      Serial.println("% received");
    }

    if (startReceived) {
      message += receivedCharacter;
      Serial.println("received");
    }

    if (receivedCharacter == "#") {
      startReceived = true;
      Serial.println("# received");
    }
  }
}
