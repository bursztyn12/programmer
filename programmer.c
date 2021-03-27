#include <wiringPi.h>
#include <wiringShift.h>
#include <string.h>

#define SHIFT_DATA      21
#define SHIFT_CLK       12
#define SHIFT_RSCLK     10

int setupWiringPi(){
  printf("Test wiringPi\n");
  if (wiringPiSetupGpio() == -1){
      printf("Error,can't start wiringPi!\n");
      return 1;
  }

  printf("Succes,library wiringPi loaded!\n");
  return 0;
}


void setupPins(){
    pinMode(SHIFT_DATA, OUTPUT);
    pinMode(SHIFT_CLK, OUTPUT);
    pinMode(SHIFT_RSCLK, OUTPUT);
}

void setAddress(int address){
    shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, address);
    digitalWrite(SHIFT_RSCLK, LOW);
    digitalWrtite(SHIFT_RSCLK, HIGH);
    digitalWrite(SHIFT_RSCLK, LOW);
}

int main(){
    setupWiringPi();
    setupPins();
    setAddress(0xff);
}