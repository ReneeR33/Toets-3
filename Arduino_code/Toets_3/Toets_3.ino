//setting the default mode
String currentInput = "TEMPERATURE_C";

void setup() {
  Serial.begin(9600);
  StartMeasuring();
  StartScreen();
}


void loop() {
  currentInput = ChangeMode(currentInput);
  //Temperature mode
  if ((currentInput == "TEMPERATURE_C") || (currentInput == "TEMPERATURE_F")) {
    float temp = Temperature();
    ChangeColorT(temp);
    //Check if the unit should be fahrenheit
    if(currentInput == "TEMPERATURE_F"){
      temp = ToFahrenheit(temp);
    }
    ValueToScreen(temp);
    PrintValuesToSerialPort(temp, currentInput);
  }

  //Humidity mode
  else if (currentInput == "HUMIDITY") {
    float hum = Humidity();
    ChangeColorH(hum);
    ValueToScreen(hum);
    PrintValuesToSerialPort(hum, currentInput);
  }
}
