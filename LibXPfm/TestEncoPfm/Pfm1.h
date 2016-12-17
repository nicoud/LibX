// Pfm1.h   150803 24

volatile char pfm // -80  80
#define MaxVit 10
#define MaxPfm 80 

volatile char pfmCnt;

void DoPfm () {
  if (pfm > MaxPfm) pfm=MaxPfm; // saturer
  if (pfm < -MaxPfm) pfm= -MaxPfm;
  if (pfm >=0) {
     if ((pfmCnt += pfm) > MaxPfm) {
        pfmCnt -= MaxPfm;   ForwRight;    }
     else { StopRight;}
  }
  if (pfm <0) {
     if ((pfmCnt += pfm) < 0) {
        pfmCnt += MaxPfm;   BackRight;    }
     else { StopRight; }
   }
}

