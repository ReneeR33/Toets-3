String currentMode = "TEMPERATURE";

void setup() {
  Serial.begin(9600);
  //if (IsSerialDataIncoming()) {
  //message = BuildMessage();
  //}
  StartMeasuring();
  StartScreen();
}


void loop() {
  currentMode = ChangeMode(currentMode);
  if (currentMode == "TEMPERATURE") {
    float temp = Temperature();
    ValueToScreen(temp);
    ChangeColorT(temp);
    PrintValuesToSerialPort(temp, currentMode);
  }
  else if (currentMode == "HUMIDITY") {
    ValueToScreen(Humidity());
    ChangeColorH(Humidity());
  }
}
