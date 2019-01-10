#include <DHT.h>
String currentMode = "TEMPERATURE";
String message;
void setup() {
  Serial.begin(9600);
  StartMeasuring();
  if (IsSerialDataIncoming()) {
    message = BuildMessage();
  }

}


void loop() {
<<<<<<< HEAD



  Serial.println(CheckMode());
}

void ChangeMode() {
=======
  Serial.println("loop");
>>>>>>> 63a32b1e0458a065c932eb5332407cff2c7a4b49
  if (IsSerialDataIncoming()) {
    if (IsValidMessage(BuildMessage())) {
      currentMode = message;
    }
  }
}

String CheckMode() {
  ChangeMode();

  if (currentMode == "TEMPERATURE") {
    //Temp mode

    return "TEMPERATURE";
  }
  else if (currentMode == "HUMIDITY") {
    //Hum mode

    return "HUMIDITY";
  }
}

void TemperatureMode() {
  Serial.println(Temperature());
}

void HumidityMode() {
  Serial.println(Humidity());
<<<<<<< HEAD
  String message = BuildMessage();
  if (message == "TEMPERATURE") {
    ChangeColorT(Temperature());
=======

  String message = BuildMessage(); 
  if(message == "TEMPERATURE"){
     ChangeColorT(Temperature());
>>>>>>> 63a32b1e0458a065c932eb5332407cff2c7a4b49
  }
  else if (message == "HUMIDITY") {
    //SetColorH(Humidity());
  }
<<<<<<< HEAD
=======
  
>>>>>>> 63a32b1e0458a065c932eb5332407cff2c7a4b49

}
