CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -O2
SRC=src/main.c src/linked_list.c src/stack.c src/queue.c src/bst.c
OUT=ds_demo

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)