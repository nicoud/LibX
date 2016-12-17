// Xplus.inc  150803

#define bLed 5 // bit 5 PORTB (pin 13) // debug and DgTell
#define  LedOn  bitSet   (PORTB,bLed)
#define  LedOff bitClear (PORTB,bLed)
#define  LedToggle PORTB ^= (1<<bLed)
#define  PushLed !(PINB&(1<<bLed))
#define bTst 4 // bit 4 PORTB (pin 12) // debug with scope
#define  S1On  bitSet   (PORTB,bTst)
#define  S1Off bitClear (PORTB,bTst)
#define  S1Toggle PORTB ^= (1<<bTst)

//Definitions pour le PWM and PFM
#define bBackL 4  // left motor on PORTD
#define bForWL 5  // rpwm possible
#define bForWR 6  // rpwm possible  
#define bBackR 7  // right motor
// Definitions for the PFM
#define ForwLeft  bitSet  (PORTD,bForWL); bitClear(PORTD,bBackL)
#define BackLeft  bitClear(PORTD,bForWL); bitSet  (PORTD,bBackL)
#define StopLeft  bitClear(PORTD,bForWL); bitClear(PORTD,bBackL)
#define ForwRight bitSet  (PORTD,bForWR); bitClear(PORTD,bBackR)
#define BackRight bitClear(PORTD,bForWR); bitSet  (PORTD,bBackR)
#define StopRight bitClear(PORTD,bForWR); bitClear(PORTD,bBackR)
// Panic motor stop
#define StopAll  PORTD &= 0b00001111 
  // a ajouter quand les variables seront definies: (?)
  //  pwmG=0; pwmD=0; pfmG=0; pfmD=0; vitG=0; vitD=0

// Whiskers on PORTD Active Low, can be written to activate the Leds
// but do not forget to update direction
#define bWhiskLeft  2 // PORTD,2)
#define bWhiskRight 3
#define ObsL    cntCopy=CntPous;  
#define ObsR  !(PIND&(1<<WhistRight)) 

#define  LedWhiskLeftOn   bitSet   (DDRD,bWhiskLeft);bitClear (PORTB,bWhiskLeft)
#define  LedWhiskLeftOff  bitClear (DDRD,bWhiskLeft)
#define  LedWhiskRightOn  bitSet   (DDRD,bWhiskRight);bitClear (PORTB,bWhiskRight)
#define  LedWhiskRightOff bitClear (DDRD,bWhiskRight)

// Loudspeaker on RxD pin1  powered through a capacitor, no static current
#define bHp 1  // TxD  bit 1 PORTD 
#define  HpOn  bitSet   (PORTD,bS1)
#define  HpOff bitClear (PORTD,bS1)
#define  HpToggle PORTD ^= (1<<bS1)

//Encoders  Active low, do not write (possible shorts)
#define bEncoL1 0   // PortD
#define bEncoL2 1
#define bEncoR1 2
#define bEncoR2 3
#define mEnco 0x0F  // bits 0-3  inutilisé

//I2C
#define bSCK  5  // PortC
#define bSDA  4

//Xsensors control // bits 0-3 PortC, A B C D
// - defined within sensor libs

void SetupXplus() {  
  DDRD |=  0b11110010 ;  // motor and HP
  DDRD &=  0b11110011 ;  // whiskers 
  DDRB |=  0b11110000 ;  // Led  S1
  DDRC &=  0b00000000 ;  // encoders  pas X+
}


