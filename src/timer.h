#ifndef TIMER__
#define TIMER__

extern void timer_lock(void (*fn)(void), unsigned int ms);

#endif