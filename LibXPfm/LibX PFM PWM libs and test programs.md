### LibX  .h files and program examples.md

#### PFM, bidirectionnal
Pfm.h - 10 bytes routine to be called every 2ms.  
Demos TestPfmBlink.ino Two motors on pins 4 5 6 7 and
TestPfmInt.ino   Same, interrupt 60us  
References:
[*PFMvsPWM*](http://www.didel.com/PFMversusPWMforRobots.pdf) and
[*PwmPfm*](http://www.didel.com/diduino/PwmPfm.pdf) (french, mention also the BCM)  

#### PWM, bidirectionnal on pins 4,5,6,7 using analogWrite
PwmBidir.h - dans SetupXbot();	variables char  pfmL pfmR  
TestPwm.ino

#### PWM, unidirectionnal for Leds
Pwm.h - a 10 bytes routine to be called every 60us
TestPwmBlink.ino Two motors on pins 4 5 6 7
TestPwmInt.ino   Same, interrupt 60us
Le pfm est signé, valeurs de –100 à +100  Les limites sont modifiables.

#### PWM for 16 Leds on a shift register
www.didel.com/diduino/CommandeLeds.pdf (french)
PWMShiftLeds.h  
#### WS2801 and APA-01 control routines
