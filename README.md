ibY is like a Meccano. You start with simple constructions, learn from examples, 
progress toward complexity, and get rewarding results.

The programs are short, Arduino compatible, but they do not use Arduino libraries and specific pins.
Great for AtTiny controllers, fast to download on Arduino, also compatible with ESP8266, where they 
are small fish in an ocean.

LibY may look unusual to Arduino beginners, but they should realize Arduino add plenty of functions 
that slow the execution and oversize the code. Beginners are not encouraged to structure their programs, 
examples are long lists of instructions.

Let us follow 3 basic rules.
1. Give explicit name and think "actions* an not "connections". "LedOn" and not "digitaWrite(pin,level)"
2. Identify the set functions you need and restructure while doing several tests programs
3. Wrap the definitions, the variables and the functions in a .h reusable file.
