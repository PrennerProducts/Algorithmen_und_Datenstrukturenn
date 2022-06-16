CC = g++
FLAGS = -I
DEPENDENCIES = ../20_helperFunctions/helperFunctions.h
OBJECT_FILES = main.o graph.o edge.o
all: graphExample

clean:
	rm -rf graphExample graphExample.exe *.o

%.o: %.c $(DEPENDENCIES)
	$(CC) -o $@ $< $(FLAGS).

graphExample: $(OBJECT_FILES)
	$(CC) -o $@ $^ $(FLAGS).