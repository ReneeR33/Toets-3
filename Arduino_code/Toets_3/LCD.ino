#include <TFT.h>
#include <SPI.h>

#define CS 10
#define DC 9
#define RESET 8

TFT myScreen = TFT(CS, DC, RESET);
char printout[5];
char previous[5];

//turn on screen
void StartScreen() {
  myScreen.begin();
  myScreen.background(0, 0, 0);
  myScreen.stroke(255, 0, 255);
  myScreen.setTextSize(6);
}

//display values on screen
void ValueToScreen(float value) {
  int i;
  String stringValue = String(value);
  stringValue.toCharArray(printout, 5);
  if (printout[0] != NULL) {
    myScreen.stroke(0, 0, 0);
    for (i = 4; i >= 0; i -= 1) {
      if (previous[i] != printout[i]) {
        myScreen.text(previous, 0, 40);
      }
    }
  }
  myScreen.stroke(R(), G(), B());
  myScreen.text(printout, 0, 40);
  for (i = 4; i >= 0; i -= 1) {
    previous[i] = printout[i];
  }
}
