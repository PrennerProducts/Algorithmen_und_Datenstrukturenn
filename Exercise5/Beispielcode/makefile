CC = g++
FLAGS = -I
OBJECT_FILES = main.o backpack.o item.o

all: main

clean: 
	rm -rf main main.exe *.o

%.o: %.c $(DEPENDENCIES)
	$(CC) -o $@ $< $(FLAGS).

main: $(OBJECT_FILES)
	$(CC) -o $@ $^ $(FLAGS).