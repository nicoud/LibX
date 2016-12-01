
# DiTell debugging help
### Display 16 bits and display as hex to decimal numbers
Many 4-digit displays exist, controlled by 2 or 3 lines on special processor pins. **_DiTell_** is special in many ways
* It is controlled by a single output line, any free pin on your board.
* It calls for one function of 120 bytes of portable C
* The function runs on Arduino and with minor modifications on Tiny AVR with clock down to 1 MHz  
* The blocking function transfer time is 3ms
* The control with LibX interrupt takes 1 us evry 60 us and update the display every 20 ms.
* It is small and clean, easy to fit in any corner of your system
* connect with 3 wires, up to 50 cm long, or plug dirctly on your Arduino, using pin 13 you should have kept free for debugging

Understanding and checking a sensor for a robot is done using Serial.print() on the Terminal, but this does not work any more when the robot is free. With  **_DiTell_** you save 1 kbyte of code (and compile time), and need a single line of code to update the result. And read it in decimal or hex while it is transmitted in binary.

How does it works? Like the well known WS2801 PWM led, but with a relaxed timing, the **_DiTell_** decode pulses of different width. On the board, a microcontroller decide from a push button how to display the data.

Program examples may need a single adaptation to the clock frequency of your system  
