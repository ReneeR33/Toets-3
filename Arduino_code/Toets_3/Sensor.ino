#include "DHT.h"
#define DHTPIN A0 
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

void StartMeasuring(){
  dht.begin();
}

float Temperature(){
  float t = dht.readTemperature();
  return t;
}