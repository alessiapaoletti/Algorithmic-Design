CXX = gcc
OPT = -O4
SOURCE = utility.c heap.c
FLAG = -Wall -Wextra

#CXXFLAGS = -Wall -Wextra -g -std=c++11

main.x:
	$(CXX) -o $@ main.c $(SOURCE) $(FLAG)

clean:
	@rm -r *.x

.PHONY: clean all
