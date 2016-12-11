ibY is like a Meccano. You start with simple constructions, learn from examples, 
### LibX is like a Meccano with a set of sorted pieces and sub-assemblies. You start with simple constructions, learn from examples, progress toward complexity, and get rewarding results.

The program modules are short, Arduino compatible, but they do not use Arduino libraries and specific pins.
This allows rich AtTiny applications, fast download of programs on Arduino. Also compatible with ESP8266 and modern controllers, where they are small fish in their ocean.

### LibX may look unusual to Arduino beginners, it is indeed simple C programming that enphasize the use of `#define..` in place of `int..` and `digitalWrite..` in place of  `bitSet..`
With Arduino, beginners are not encouraged to structure their programs; code appear as long lists of instructions, with comments on instructions and not on block of code.

### Example of a LibX programs
```
// CoolBot1.ino 161001  2492b 46v decode G et N orders
#include "DoTell.h"   // display highLow
#include "Bips.h"
#include "Hexo.h"
#include "Ana4.h"
#include "Ordres.h"
#include "Inter.h"
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
