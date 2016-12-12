// TestEnco.ino  // Test la routine encodeur pour 1 canal
// voir TestEnco2 pour aller-retour robot
#include <Arduino.h>  //
#include "Xplus.h"
#include "Utile.h"
#include "Debug.h"
#include "Enco.h"
#include "Pfm.h"
#include "Inter.h"

int main () {
  SetupXplus();
  SetupEnco();
  SetupDebug();
  SetupInter();
Clignote(10);
  pos=0x40;
  while (1){   // loop
    pfmL=10; pfmR=10; 
    delMs(10000);
    pfmL=70; pfmR=70; 
    delMs(10000);
//    pfmL= -10; pfmR=-10;  
//    delMs (1000);
//    pfmL=0; pfmR=0; 
//    StopAll; delMs(1000); 
  }
}

