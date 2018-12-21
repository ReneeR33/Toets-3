int red;
int green;
int blue;

void SetColor(int r, int g, int b) {
  //analogWrite(LEDRoodPin, r);
  //analogWrite(LEDGroenPin, g);
  //analogWrite(LEDBlauwPin, b);
}

void ChangeColor(float temperature){
  if(temperature < 21){
    temperature *= 12,75;
  }
  if(temperature >= 21){
    
  }
}
