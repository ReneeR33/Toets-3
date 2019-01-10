#include <TFT.h> 
#include <SPI.h>

#define CS   10
#define DC   9
#define RESET  8

TFT myScreen = TFT(CS, DC, RESET);
