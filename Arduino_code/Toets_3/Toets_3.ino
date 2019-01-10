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




  Serial.println(CheckMode());
}

void ChangeMode() {

  Serial.println("loop");

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

  String message = BuildMessage();
  if (message == "TEMPERATURE") {
    ChangeColorT(Temperature());


  String message = BuildMessage(); 
  if(message == "TEMPERATURE"){
     ChangeColorT(Temperature());

  }
  else if (message == "HUMIDITY") {
    //SetColorH(Humidity());
  }


}
