CC = gcc 
LDFLAGS = `sdl2-config --libs` -lSDL2 -lSDL2_ttf -lm
PROG = sdl-game-of-life

SRCS = $(addprefix src/, main.c init.c global.c game_of_life.c colors.c utils.c text.c timer.c)

OBJS = $(SRCS:.c=.o)

all: $(PROG)
# linking the program
$(PROG): ${OBJS}
		${CC} ${OBJS} -o ${PROG} ${LDFLAGS}

clean:
	rm -f $(PROG) $(OBJS)

run:
	./${PROG}