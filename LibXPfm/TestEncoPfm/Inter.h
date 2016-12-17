// Inter.h tous les inter

volatile byte cnt,cnte;
ISR (TIMER2_OVF_vect) {
 TCNT2 = 141;  //  58 us calibre avec corr
 SendS1(); 
 if (cnte++ > 20) {cnte=0; // toutes les 20x58= 1ms 
   DoEnco();  // tous les 1ms
   if (cnt&1) { DoPfm(); }  // toutes les 2ms
   if (cnt++ > 50) {cnt=0; // toutes les 50x1= 50ms 
     vit = posOld-pos; posOld=pos;
     highLow = (vit*256)+(pos&0xFF);
     flagS1 = 1;
   }
 } 
}

void SetupInter() {  // initialisation
  TCCR2A = 0; //default
  TCCR2B = 0b00000010;  // clk/8
  TIMSK2 = 0b00000001;  // TOIE2
  sei();
}



