#include <TFT.h> 
#include <SPI.h>

#define CS   10
#define DC   9
#define RESET  8

TFT myScreen = TFT(CS, DC, RESET);
char printout[5];


void StartScreen(){
  myScreen.begin();
  myScreen.background(0, 0, 0);
  myScreen.stroke(255, 0, 255);
  myScreen.setTextSize(11);
}

void ValueToScreen(float value){
  if (printout[0] != NULL){
    myScreen.stroke(0,0,0);
    myScreen.text(printout,0,30);
  }
  String stringValue = String(value);
  stringValue.toCharArray(printout,5);
  myScreen.stroke(255,255,255);
  myScreen.text(printout,0,30);
  
}
