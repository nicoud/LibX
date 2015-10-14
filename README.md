![](Didel400.jpg)

# LibX

One timer interrupt round-robin multitask library for mobile robots.

Traditionally, a set of process interrupt the processor randomly. The main program may be interrupted for a too long time, or some interrupt may not be serviced in time.
Our paradigm is inspired from synchronous programming, with a slot of time givent to every task. It is very efficient within Arduino-like environments consisting of a 10 to 20 MHz microcontroller having at least one timer (they have all !). The library is written in C, used extensibely with the Xbot robot under Arduino and AvrStudio. Programs are very compact. Libraries are indeed included .h files, parts of the sketch. For the programmer with a little experience, the -h files are ready to use models easy to adapt to the application if required. An extensive use of state machines reduce the execution time at every interrupt (e.g. 50 to 100 us) and response time for a given action (measuring a sensor) is kept in the 10ms range. The main program access to a set of variables updated every 10-20ms. This fits perfectly hobby robotics and domotics applications.
