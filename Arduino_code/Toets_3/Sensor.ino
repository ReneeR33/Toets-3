#include <DHT.h>
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

float Humidity(){
  float h = dht.readHumidity();
  return h;
}

float ToFahrenheit(float value){
 value = (value * 1,8) + 32;
 return value;
}
