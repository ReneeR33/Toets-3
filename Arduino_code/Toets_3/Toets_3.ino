String currentMode = "TEMPERATURE";
String message;
void setup() {
  Serial.begin(9600);
  //if (IsSerialDataIncoming()) {
  //message = BuildMessage();
  //}
  StartMeasuring();
  StartScreen();
}


void loop() {
  if (currentMode == "TEMPERATURE") {
    ValueToScreen(Temperature());
    ChangeColorT(Temperature());
  }
  else if(currentMode == "HUMIDITY"){
    ValueToScreen(Humidity());
    ChangeColorH(Humidity());
  }
}

void ChangeMode() {

  Serial.println("loop");

  if (IsSerialDataIncoming()) {
    if (IsValidMessage(BuildMessage())) {
      currentMode = message;
    }
  }
}
