String currentInput = "TEMPERATURE";
String tempUnit = "CELSIUS";

void setup() {
  Serial.begin(9600);
  StartMeasuring();
  StartScreen();
}


void loop() {
  currentInput = ChangeMode(currentInput);
  if (currentInput == "TEMPERATURE") {
    float temp = Temperature();
    ValueToScreen(temp);
    ChangeColorT(temp);
    PrintValuesToSerialPort(temp, currentInput);
  }
  else if (currentInput == "HUMIDITY") {
    float hum = Humidity();
    ValueToScreen(hum);
    ChangeColorH(hum);
    PrintValuesToSerialPort(hum, currentInput);
  }
}
