
//setting the default mode
String currentMode = "TEMPERATURE_C";

void setup() {
  Serial.begin(9600);
  StartMeasuring();
  StartScreen();
}


void loop() {
  currentMode = ChangeMode(currentMode);
  //Temperature mode
  if ((currentMode == "TEMPERATURE_C") || (currentMode == "TEMPERATURE_F")) {
    float temp = Temperature();
    ChangeColorT(temp);
    if (currentMode == "TEMPERATURE_F") {
      temp = ToFahrenheit(temp);
    }
    ValueToScreen(temp);
    PrintValuesToSerialPort(temp, currentMode);
  }

  //Humidity mode
  else if (currentMode == "HUMIDITY") {
    float hum = Humidity();
    ChangeColorH(hum);
    ValueToScreen(hum);
    PrintValuesToSerialPort(hum, currentMode);
  }
}
