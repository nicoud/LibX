### LibX is like a Meccano with a set of sorted pieces and sub-assemblies. You start with simple constructions, learn from examples, progress toward complexity, and get rewarding results.

The program modules are short, Arduino compatible, but they do not use Arduino libraries and specific pins.
This allows rich AtTiny applications, fast download of programs on Arduino. Also compatible with ESP8266 and modern controllers, where they are small fish in their ocean.

### LibX may look unusual to Arduino beginners, it is indeed simple C programming that enphasize the use of `#define..` in place of `int..` and `digitalWrite..` in place of  `bitSet..`
With Arduino, beginners are not encouraged to structure their programs; code appear as long lists of instructions, with comments on instructions and not on block of code.

### Example of a LibX program
```
// CoolBot.ino   decode G et N orders
#include "DoTell.h"   // display highLow
#include "Bips.h"     // ack bips
#include "Hexo.h"     // get hexo orders
#include "Ana4.h"     // read the 4 A/D channels
#include "Ordres.h"   // decode Hexo orders
#include "Inter.h"    // handle interrupts
void setup() {                
  SetupTell();
  SetupBips ();
  SetupHexo();
  SetupAna();
  SetupInter(); // all actions by interrupt
}
void loop () {
 highLow= hCnt;
}
```

See __LibX rules and simplistic example__ to continue
