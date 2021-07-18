VALGRIND_OPTS = \
--leak-check=full \
--show-leak-kinds=all \
-s  

all: build

build:
	$(CC) -o example -Wall -Werror -g example.c mempool.c

test: build
	# valgrind $(VALGRIND_OPTS) ./example
	# valgrind --tool=massif ./example
	./example

clean:
	$(RM) -f example