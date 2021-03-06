Continuation of LibX README.md
## LibX rules and simplest example
### Let us follow 3 basic rules:
1. Give explicit name and think "actions* and not "connections". "LedOn" and not "digitaWrite(pin,level)"
2. Identify the required set functions and restructure while doing several tests programs
3. Wrap in a .h reusable file the definitions, the connections, the variables and the functions for a given interface, sensor, set of functionnalities, etc..

     *Not familiar with #include? - see  xx coming*

## Example: a LED is On for 10 seconds when you depress a button.
### Top-down analysis
1. What is the algorithm? Is it a simple copy of a button on a LED? Has button action to last for several ms before getting accepted? What happens if button is depressed when LED is on? Is it ignored or it restarts the 10s delay? What happens if the button is blocked depressed?
2. How many inputs and outputs do we need? Button is one input plus ground or plus Vcc? Is a pull-up or pull-down required? LED is connected to one output with a serial resistor or LED is shorted?
3. Which microcontroller pins can be used, according to current and voltage limitations? Have all pins an optional pull-up resistor?

### Bottom-up programming
1. Defines the wiring and the low-level actions
2. Write several test programs to completely understand what has to be executed. Keep the test prograns that will be useful for debugging
3. Document the reference program that uses the created .h file, to be used or adapted when similar problems occurs.

![](SimpleEx.jpg)
#### Back to our example.
1. A button is connected to Arduino pin 3, Gnd on other side. LED is connected to pin 13, active low (limiting resistance toward +Vcc).
```
#define pinBUTTON 3  // active low
#define pinLED 13  // active low
#define BUTTONdepressed (!digitalRead(bBUTTON)) // on if zero
#define LedOn  digitalWrite (bLED,LOW)
#define LedOff digitalWrite (bLED,HIGH)
void SetupButtonLed () {
     pinMode (pinBUTTON,INPUT);
     pinMode (pinLED,OUTPUT);
     digitalWrite (pinBUTTON,HIGH); // pull-up
}
```
There are rules with C: variables are lower case, functions have a first letter is upper case, constants are all letters upper case. We not alway follow these rules, e.g. we feel LedOn is more readable as LEDON. What is important is to be consistant.  
If you plan to use AVRstudio or some other IDE, you cannot use these familiar Arduino functions, which have the problem to be very slow and use ten times more memory space. But within definitions, it is acceptable and frequently it is more easy to understand the functionnality. Indeed, it's a question of habit.
```
#define bBUTTON 3  // PortD bit 3 active low
#define bLED 5     // PortB bit 5 active low
#define Buttondepressed (PIND &= (1<<bBUTTON))  
    // or bitTest (PIND,bBUTTON)
#define LedOn  PORTD |= (1<<bLED) // or bitSet (PORTD,bLED)
#define LedOff digitalWrite (bLED,HIGH)// or bitClear (PORTD,bLED)
void SetupButtonLed () {
     DDRB &= 0b11110111;  // bit 3 button in
     DDRD |= 0b00100000;  // bit 5 led out
}
```
The definitions depends on the hardware, on your hardware. They can also depends on your habits writing code. If you are not familiar with bits, bytes and logic operations, no problem to use Arduino notations. But within the program digitalWrite and bitSet for pins must not be used for readability and portability reasons.

2. Let us program the simple case, the button triggers the led.
```
void loop() {
     while (!BUTTONdepressed) {} // wait
     LedOn;
     delay (10000);
     LedOff;
}
```

3. Let us create a `ButtonLed.h` "library"
Together with the defines and setup, we create a file CopyButton.h and we can include it within programs when we need to see if the button is depressed.

```
// ButtonLed.h  *library"
#define pinBUTTON 3  // active low
#define pinLED 14    // active low
#define BUTTONdepressed digitalRead(bBUTTON)
#define LedOn  digitalWrite (bLED,LOW)
#define LedOff digitalWrite (bLED,HIGH)
void SetupCopyButton () {
   pinMode (pinBUTTON,INPUT);
   pinMode (pinLED,OUTPUT);
}
```
Now a program can include ButtonLed.h and the low level definitions are hidden. Examples for Arduino and AVRstudio are given below.
```
// StaircaseTimer.ino  for Arduino
#include ButtonLed.h
setup () {
    SetupButtonLed();
}
void loop () {
    while (!BUTTONdepressed) {} // wait
    LedOn;
    delay (10000);
    LedOff;    
}

// StaircaseTimer.c  for AVRstudio
#include ButtonLed.h
void main () {
  SetupButtonLed();
  while (1) {
    while (!BUTTONdepressed) {} // wait
    LedOn;
    delay (10000);
    LedOff;
  }
}
```
#### See the LibX list to get an idea what is already proposed.
