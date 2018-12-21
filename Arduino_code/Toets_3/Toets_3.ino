#include <DHT.h>

void setup() {
  
  Serial.begin(9600); 
  Serial.begin("Start ");
  StartMeasuring();
 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop");
  CheckForCommunication();
}
