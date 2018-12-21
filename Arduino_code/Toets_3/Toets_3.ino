#include <DHT.h>

void setup() {
  
  StartMeasuring();
 
}

void loop() {
  String message = BuildMessage(); 
  if(message == "TEMPERATURE"){
     ChangeColorT(Temperature());
  }
  else if(message == "HUMIDITY"){
    //SetColorH(Humidity());
  }
  
}
