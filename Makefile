CC = gcc 
LDFLAGS = `sdl2-config --libs` -lSDL2 -lSDL2_ttf -lm
PROG = sdl-game-of-life

SRCS = $(addprefix src/, main.c init.c global.c game_of_life.c colors.c utils.c text.c timer.c draw.c terminal_gol.c sdl_gol.c log.c)

OBJS = $(SRCS:.c=.o)

# set the default mode to sdl
OPT = sdl

.PHONY:up
up: ## build and run the app
	make clean build
	./${PROG} ${OPT}

.PHONY:build
build: $(PROG)	## compiles the app to binary 
# linking the program

$(PROG): ${OBJS}
		${CC} ${OBJS} -o ${PROG} ${LDFLAGS}

.PHONY:clean
clean: ## removes binary and object files
	rm -f $(PROG) $(OBJS)

.PHONY:help
help: ## Show this help
	@echo "----------------------------------------------------------------------"
	@echo "The purpose of this Makefile is to simplify common development tasks."
	@echo "----------------------------------------------------------------------"
	@echo ""
	@awk -F ':.*?## ' '/^[^\t].+?:.*?## .*$$/ { printf "%-20s %s\n\n", $$1, $$2 }' $(MAKEFILE_LIST)