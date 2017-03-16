all: reverse_words

main.o: main.c
	gcc -c -o main.o main.c
mylist.o: mylist.c
	gcc -c -o mylist.o mylist.c
WordList.o: WordList.c
	gcc -c -o WordList.o WordList.c
reverse_words: main.o mylist.o WordList.o
	gcc -o reverse_words main.o mylist.o WordList.o
