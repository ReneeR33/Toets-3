#include <DHT.h>
#define DHTPIN A0 
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

void StartMeasuring(){
  dht.begin();
}

//check Temperature
float Temperature(){
  float t = dht.readTemperature();
  return t;
}

//check Humidity
float Humidity(){
  float h = dht.readHumidity();
  return h;
}

//converts Celsius to Fahrenheit
float ToFahrenheit(float value){
 value = (value * 1.8) + 32;
 return value;
}
