# SDL Game of Life

SDL Game of Life is a C implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life), a cellular automaton game that simulates the evolution of a grid of cells according to specific rules. The project is built using the SDL library and can be run in both an SDL app mode and a terminal app mode.

## SDL app mode

![sdl-game-of-life](./docs/sdl-game-of-life.png)

## Terminal app mode

```bash
1	1	1	1	1	0	1	1	1	1	1	1	1	1	0
0	1	0	0	0	0	0	0	1	1	0	1	0	0	1
1	1	0	0	0	1	1	1	0	0	0	1	1	1	0
1	0	1	0	0	1	0	1	1	1	0	1	1	1	1
0	0	0	0	0	0	1	1	0	1	1	0	1	0	0
1	0	0	1	0	0	0	0	1	0	1	0	1	0	1
1	0	1	1	0	1	0	1	1	0	1	0	0	0	1
0	1	1	0	0	1	1	1	1	0	1	0	0	0	1
1	1	1	0	1	0	0	1	1	1	1	0	1	1	0
0	0	0	1	0	0	0	1	1	1	0	0	0	0	1
1	0	0	0	0	1	0	0	0	0	1	1	0	1	1
1	1	1	1	1	1	1	1	1	1	1	1	1	1	1
0	0	1	1	0	0	0	1	0	1	1	0	0	1	1
1	0	0	0	1	1	0	1	1	1	0	0	0	1	1
1	0	1	1	1	1	1	1	0	1	0	1	1	1	1

Generation 0

1	1	1	1	0	0	0	1	0	0	0	1	1	1	0
0	0	0	1	1	0	0	0	0	0	0	0	0	0	1
1	0	1	0	0	1	0	0	0	0	0	0	0	0	0
1	0	0	0	0	1	0	0	0	1	0	0	0	0	1
0	1	0	0	0	0	1	0	0	0	0	0	0	0	1
0	1	1	1	1	0	0	0	0	0	1	0	0	0	0
1	0	0	1	0	1	0	0	0	0	1	0	0	0	1
0	0	0	0	0	1	0	0	0	0	1	0	0	0	1
1	0	0	0	1	1	0	0	0	0	1	1	0	1	1
1	0	1	1	1	0	1	1	0	0	0	0	0	0	1
1	0	0	0	0	1	0	0	0	0	0	0	0	0	0
1	0	0	0	0	1	0	1	0	0	0	0	0	0	0
1	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	0	0	1	0	0	0
0	1	0	1	0	0	0	1	0	1	1	0	1	0	1

Generation 1

0	1	1	1	1	0	0	0	0	0	0	0	1	1	0
1	0	0	0	1	0	0	0	0	0	0	0	1	1	0
0	1	0	1	0	1	0	0	0	0	0	0	0	0	0
1	0	0	0	0	1	1	0	0	0	0	0	0	0	0
1	1	0	1	1	1	0	0	0	0	0	0	0	0	0
1	1	0	1	1	1	0	0	0	0	0	0	0	0	0
0	1	0	1	0	1	0	0	0	1	1	1	0	0	0
0	0	0	0	0	1	1	0	0	1	1	0	0	0	1
0	1	0	0	0	0	0	0	0	0	1	1	0	1	1
1	0	0	1	0	0	1	0	0	0	0	0	0	1	1
1	0	0	1	0	1	0	1	0	0	0	0	0	0	0
1	1	0	0	0	0	1	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	0	1	1	0	0	0
0	0	0	0	0	0	0	0	0	0	1	1	0	0	0

Generation 2
```

## Ubuntu Prerequisites

Before you can build and run SDL Game of Life, make sure you have the following installed on your system:

1.  [Make](https://www.gnu.org/software/make/)
2.  GCC (`apt install gcc`)
3.  SDL library (`apt-get install libsdl2-ttf-dev`)

### How to Build and Run

To build the project and run it in SDL app mode, run the following command:

```bash
$ make
```

Alternatively, to explicitly build and run the project in SDL app mode, run:

```bash
$ make OPT=sdl
```

To build and run the project in terminal app mode, run:

```bash
$ make OPT=terminal
```

## Build Options

-   `sdl`: builds the project with an SDL interface and runs it in app mode
-   `terminal`: builds the project with a terminal interface and runs it in terminal mode
