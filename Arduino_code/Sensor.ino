DHT dht(DHTPIN, DHTTYPE);

float Temperature(){
  float t = dht.readTemperature();
  return t;
}
