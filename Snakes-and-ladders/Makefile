CC = clang
CFLAGS = -Wall -Wextra -Werror -Iboard

SRC = \
    main.c \
    board/board.c \
    board/board_1.c \
    board/board_2.c \
    board/board_3.c \
    board/board_4.c \
    simulator.c \
    graph.c

OBJ = $(SRC:.c=.o)
BIN = play

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(BIN)

.PHONY: all clean
