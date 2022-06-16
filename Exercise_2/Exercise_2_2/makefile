CC = g++
FLAGS = -I
OBJECT_FILES = main.o extendedListItem.o doublyLinkedList.o

all: list

clean:
	rm -rf list list.exe *.o

%.o: %.c $(DEPENDENCIES)
	$(CC) -c -o $@ $< $(FLAGS).

list: $(OBJECT_FILES)
	$(CC) -o $@ $^ $(FLAGS).