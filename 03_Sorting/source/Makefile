CXX = gcc
OPT = -O4
SOURCE = utility.c heap.c sorting.c select.c
FLAG = -Wall -Wextra

#CXXFLAGS = -Wall -Wextra -g -std=c++11
all: sortingMain.x selectTest.x

sortingMain.x:
	$(CXX) -o $@ sortingMain.c $(SOURCE) $(FLAG) -lm

selectTest.x:
	$(CXX) -o $@ selectTest.c $(SOURCE) -lm

clean:
	@rm -r *.x

.PHONY: clean all
