OBJS = main.o bst.o bstNode.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: totalProgram

totalProgram: $(OBJS)
	$(CC) -o totalProgram $(OBJS) $(LFLAGS)

main.o: main.cpp bst.h bst.cpp bstNode.h bstNode.cpp
	$(CC) $(CFLAGS) main.cpp

bst.o: bst.h bst.cpp bstNode.h
	$(CC) $(CFLAGS) bst.cpp

bstNode.o: bstNode.h bstNode.cpp
	$(CC) $(CFLAGS) bstNode.cpp

clean:
	rm -rf *.o totalProgram