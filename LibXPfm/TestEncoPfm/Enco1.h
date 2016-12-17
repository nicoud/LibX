// Enco1.h

#define bP1  1 // PORTC  
#define bP2  0
#define   P1On  !(PINC&(1<<bP1)) 
#define   P2On  !(PINC&(1<<bP2))
#define bRecG 4 // PORTD
#define bAvG 5
#define   AvG   bitSet  (PORTD,bAvG); bitClear(PORTD,bRecG)
#define   RecG  bitClear(PORTD,bAvG); bitSet  (PORTD,bRecG)
#define   StopG bitClear(PORTD,bAvG); bitClear(PORTD,bRecG)

volatile int pos=0, posOld=0 ;  // global
volatile int vit=0 ;
void SetupEnco() {  
  DDRC &=  0b11110000 ; 
}
enum {e0,e1,e2,e3}; byte next = e0;
////volatile int pos=0 ;
void DoEnco () {
 switch(next) {
  case e0: 
    if (P1On) {pos++; next = e1; }
    if (P2On) {pos--; next = e3; }
    break;
  case e1: 
    if (P2On)  {pos++; next = e2; }
    if (!P1On) {pos--; next = e0; }
    break;
  case e2: 
    if (!P1On) {pos++; next = e3; }
    if (!P2On) {pos--; next = e1; }
    break;
  case e3:
    if (!P2On) {pos++; next = e0; }
    if (P1On)  {pos--; next = e2; }
    break; 
  }
}
