## LibX is a set of C/Arduino include files to handle your tasks. Need to convert to BCD, call a running average function, read a SR05 not using pulseIn(). We have started to document all the functions we use. Simple C, simple to understand, simple to adapt.

#### LibX is like a Meccano. You start with simple constructions, learn from examples, progress toward complexity, and get rewarding results.

The programs are shorts, Arduino compatible, but they do not use Arduino libraries and specific pins.
Great for AtTiny controllers, fast to download on Arduino, also compatible with ESP8266, where they
are small fish in an ocean.

#### LibY may look unusual to Arduino beginners, used to see digitalWrite everywhere in the program.
Beginners are not encouraged to structure their programs, use definitions and include files to avoid long lists of instructions.

#### Let us follow 3 basic rules.
1. Give explicit name and think "actions* an not "connections". "LedOn" and not "digitaWrite(pin,level)"
2. Identify the set of required functions and restructure while doing several tests programs
3. Wrap the definitions, the variables and the functions in a .h reusable file.
