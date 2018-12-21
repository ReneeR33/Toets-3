int red;
int green;
int blue;

#define LEDRoodPin 11
#define LEDGroenPin 9
#define LEDBlauwPin 10

void SetColor(int r, int g, int b) {
  //analogWrite(LEDRoodPin, r);
  //analogWrite(LEDGroenPin, g);
  //analogWrite(LEDBlauwPin, b);
}

void ChangeColor(float temperature){
  temperature *= 12,75;
  if(temperature <= 255){
    
  }
  if((temperature > 255) && (temperature <= 510)){
    
  }
}
