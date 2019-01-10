#define LEDRoodPin 6
#define LEDGroenPin 3
#define LEDBlauwPin 5

void SetPinModeLed() {
  pinMode (LEDRoodPin, OUTPUT);
  pinMode (LEDGroenPin, OUTPUT);
  pinMode (LEDBlauwPin, OUTPUT);
}

void SetColor(float r, float g, float b) {
  analogWrite(LEDRoodPin, r);
  analogWrite(LEDGroenPin, g);
  analogWrite(LEDBlauwPin, b);
}

void ChangeColorT(float temperature) {
  temperature *= 12, 75;
  if ((temperature >= 0) && (temperature <= 255)) {
    SetColor(temperature, 0, 255);
  }
  else if ((temperature > 255) && (temperature <= 510)) {
    temperature -= 255;
    SetColor(255, 0, temperature);
  }
  else if (temperature < 0) {
    SetColor(0, 0, 255);
  }
  else {
    SetColor(255, 0, 0);
  }
}

void ChangeColorH(float humidity) {
  humidity *= 5, 1;
  if (humidity <= 255) {
    SetColor(0, 255, humidity);
  }
  else {
    SetColor(0, humidity, 255);
  }
}
