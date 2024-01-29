## ----------------------------------------------------------------------
## The purpose of this Makefile is to simplify common development tasks.
## ----------------------------------------------------------------------
##
## Usage:
##   - make sdl          : Build and run the SDL application
##   - make terminal     : Build and run the application in the terminal
##   - make build        : Compile the application to binary
##   - make clean        : Remove binary and object files
##   - make help         : Show available commands and descriptions
##

CC = gcc 
LDFLAGS = `sdl2-config --libs` -lSDL2 -lSDL2_ttf -lm
PROG = $(shell basename `git rev-parse --show-toplevel`)

SRCS = $(addprefix src/, main.c init.c global.c game_of_life.c colors.c utils.c text.c timer.c draw.c terminal_gol.c sdl_gol.c log.c)

OBJS = $(SRCS:.c=.o)


.PHONY:sdl
sdl:
	make clean build
	./${PROG}

.PHONY:terminal
terminal:
	make clean build
	./${PROG} terminal

.PHONY:build
build: $(PROG)

$(PROG): ${OBJS}
		${CC} ${OBJS} -o ${PROG} ${LDFLAGS}

.PHONY:clean
clean:
	rm -f $(PROG) $(OBJS)

.PHONY:help
help:
	@sed -ne '/@sed/!s/##//p' $(MAKEFILE_LIST)