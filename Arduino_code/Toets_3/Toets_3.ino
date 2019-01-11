<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
//setting the default mode
=======
>>>>>>> parent of 14dc7d5... Naam veranderd
=======
>>>>>>> parent of 14dc7d5... Naam veranderd
=======
>>>>>>> parent of 14dc7d5... Naam veranderd
=======
>>>>>>> parent of 14dc7d5... Naam veranderd
String currentInput = "TEMPERATURE_C";
=======
String currentInput = "TEMPERATURE_F";
>>>>>>> parent of 72261b1... fahrenheit bug gefixed

void setup() {
  Serial.begin(9600);
  StartMeasuring();
  StartScreen();
}


void loop() {
  currentInput = ChangeMode(currentInput);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  //Temperature mode
  if ((currentInput == "TEMPERATURE_C") || (currentInput == "TEMPERATURE_F")) {
    float temp = Temperature();
    ChangeColorT(temp);
    //Check if the unit should be fahrenheit
=======
  if ((currentInput == "TEMPERATURE_C") || (currentInput == "TEMPERATURE_F")) {
    float temp = Temperature();
    ChangeColorT(temp);
>>>>>>> parent of 14dc7d5... Naam veranderd
=======
  if ((currentInput == "TEMPERATURE_C") || (currentInput == "TEMPERATURE_F")) {
    float temp = Temperature();
    ChangeColorT(temp);
>>>>>>> parent of 14dc7d5... Naam veranderd
=======
  if ((currentInput == "TEMPERATURE_C") || (currentInput == "TEMPERATURE_F")) {
    float temp = Temperature();
    ChangeColorT(temp);
>>>>>>> parent of 14dc7d5... Naam veranderd
=======
  if ((currentInput == "TEMPERATURE_C") || (currentInput == "TEMPERATURE_F")) {
    float temp = Temperature();
    ChangeColorT(temp);
>>>>>>> parent of 14dc7d5... Naam veranderd
    if(currentInput == "TEMPERATURE_F"){
      temp = ToFahrenheit(temp);
    }
    ValueToScreen(temp);
    PrintValuesToSerialPort(temp, currentInput);
  }
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD

  //Humidity mode
=======
>>>>>>> parent of 14dc7d5... Naam veranderd
=======
>>>>>>> parent of 14dc7d5... Naam veranderd
=======
>>>>>>> parent of 14dc7d5... Naam veranderd
=======
>>>>>>> parent of 14dc7d5... Naam veranderd
  else if (currentInput == "HUMIDITY") {
    float hum = Humidity();
    ChangeColorH(hum);
    ValueToScreen(hum);
    PrintValuesToSerialPort(hum, currentInput);
  }
}
