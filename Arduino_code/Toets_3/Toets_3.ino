#include <DHT.h>
String currentMode = "TEMPERATURE";
String message;
void setup() {
  Serial.begin(9600);
  //StartMeasuring();
  //if (IsSerialDataIncoming()) {
    //message = BuildMessage();
  //}
  SetColor(255,0,0);

}


void loop() {


  //Serial.println(Temperature())

  //Serial.println(CheckMode());
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
