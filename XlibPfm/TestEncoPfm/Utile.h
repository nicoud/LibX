// Utile.h   Inspir'e de Arduino, en C
// delMs ();  identique a delay(); -- utiliser les Timers et Timouts
// clignote (5); 5 fois ~2Hz

typedef unsigned char byte;

#define Calib1ms 900  // 1ms at 16 MHz 10 Mega --> 560, 1 MHz --> 56
void delMs (int dm) { 
   for (volatile int i=0; i<dm; i++) {
      for (volatile int j=0; j<Calib1ms; j++) {}
   }
}

void Clignote (byte ct) {
  for (byte i=0; i<ct; i++) {
    LedToggle; delMs (200);
  }
}


