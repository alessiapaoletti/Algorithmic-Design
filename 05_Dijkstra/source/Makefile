CXX = gcc
OPT = -O4
SOURCE = heap.c 
FLAG = -Wall -Wextra

all: main.x

main.x:
	$(CXX) -o $@ main.c $(SOURCE) $(FLAG)

clean:
	@rm -r *.x

.PHONY: clean all
