String currentInput = "TEMPERATURE_F";

void setup() {
  Serial.begin(9600);
  StartMeasuring();
  StartScreen();
}


void loop() {
  currentInput = ChangeMode(currentInput);
  if ((currentInput == "TEMPERATURE_C") || (currentInput == "TEMPERATURE_F")) {
    float temp = Temperature();
    ChangeColorT(temp);
    if(currentInput == "TEMPERATURE_F"){
      temp = ToFahrenheit(temp);
    }
    ValueToScreen(temp);
    PrintValuesToSerialPort(temp, currentInput);
  }
  else if (currentInput == "HUMIDITY") {
    float hum = Humidity();
    ChangeColorH(hum);
    ValueToScreen(hum);
    PrintValuesToSerialPort(hum, currentInput);
  }
}
