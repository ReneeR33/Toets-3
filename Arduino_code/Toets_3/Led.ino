#define LEDRoodPin 11
#define LEDGroenPin 9
#define LEDBlauwPin 10

void SetPinModeLed(){
  pinMode (LEDRoodPin, OUTPUT);
  pinMode (LEDGroenPin, OUTPUT);
  pinMode (LEDBlauwPin, OUTPUT);
}

void SetColor(int r, int g, int b) {
  analogWrite(LEDRoodPin, r);
  analogWrite(LEDGroenPin, g);
  analogWrite(LEDBlauwPin, b);
}

void ChangeColor(float temperature){
  //temperature.round();
  temperature *= 12,75;
  if(temperature <= 255){
    SetColor(temperature, 0, 255);
    
  }
  if((temperature > 255) && (temperature <= 510)){
    temperature -= 255;
    SetColor(255, 0, temperature);
  }
}
