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
}
