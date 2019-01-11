#define LEDRoodPin 6
#define LEDGroenPin 5
#define LEDBlauwPin 3

float red; float green; float blue;

float R(){
  return red;
}

float G(){
  return green;
}

float B(){
  return blue;
}

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
  temperature *= 12.75;
  if ((temperature >= 0) && (temperature <= 255)) {
    SetColor(temperature, 0, 255);
    red = temperature; green = 0; blue = 255;
  }
  else if ((temperature > 255) && (temperature <= 510)) {
    temperature -= 255; temperature = 255 - temperature;
    SetColor(255, 0, temperature);
    red = 255; green = 0; blue = temperature;
  }
  else if (temperature < 0) {
    SetColor(0, 0, 255);
    red = 0; green = 0; blue = 255;
  }
  else {
    SetColor(255, 0, 0);
    red = 255; green = 0; blue = 0;
  }
}

void ChangeColorH(float humidity) {
  humidity *= 5.1;
  if (humidity <= 255) {
    SetColor(0, 255, humidity);
    red = 0; green = 255; blue = humidity;
  }
  else {
    humidity -= 255; humidity = 255 - humidity;
    SetColor(0, humidity, 255);
    red = 0; green = humidity; blue = 255;
  }
}
