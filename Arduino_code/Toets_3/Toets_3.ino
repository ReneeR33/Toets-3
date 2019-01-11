String currentMode = "TEMPERATURE";

void setup() {
  Serial.begin(9600);
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
    float hum = Humidity();
    ValueToScreen(hum);
    ChangeColorH(hum);
    PrintValuesToSerialPort(hum, currentMode);
  }
}
