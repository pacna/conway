#ifndef TIMER__
#define TIMER__

extern void set_sdl_timeout(void (*fn)(void), int ms);
extern void set_terminal_timeout(void (*fn)(void), int ms);

#endif