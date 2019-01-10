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
  Serial.println("loop");
  if (IsSerialDataIncoming()) {
      Serial.println("input");
    if (IsValidMessage(BuildMessage())) {
        Serial.println("valid");
      currentMode = message;
      CheckMode();
    }
    else {
      CheckMode();
    }
  }
  else {
    CheckMode();
  }
}

void CheckMode() {
  if (currentMode == "TEMPERATURE") {
    //Temp mode
  }
  else if (currentMode == "HUMIDITY") {
    //Hum mode
  }
}

void TemperatureMode() {
  Serial.println(Temperature());
}

void HumidityMode() {
  Serial.println(Humidity());
=======
  String message = BuildMessage(); 
  if(message == "TEMPERATURE"){
     ChangeColorT(Temperature());
  }
  else if(message == "HUMIDITY"){
    //SetColorH(Humidity());
  }
  
>>>>>>> 5117495e4b0074f38d82a7f9fdc4e78b3d450c8c
}
