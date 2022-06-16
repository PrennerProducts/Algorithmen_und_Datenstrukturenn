CC = g++
FLAGS = -I
OBJECT_FILES = main.o pbEntry.o hashTableChaining.o Ware.o

all: main

clean: 
	rm -rf main main.exe *.o

%.o: %.c $(DEPENDENCIES)
	$(CC) -o $@ $< $(FLAGS).

main: $(OBJECT_FILES)
	$(CC) -o $@ $^ $(FLAGS).

