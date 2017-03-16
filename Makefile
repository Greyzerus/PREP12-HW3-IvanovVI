reverse_words: main.o mylist.o WordList.o
	gcc -o reverse_words main.o mylist.o WordList.o
main.o: main.c
	gcc -c -o main.o main.c
mylist.o: mylist.c
	gcc -c -o mylist.o mylist.c
WordList.o: WordList.c
	gcc -c -o WordList.o WordList.c
reverse_words: main.o mylist.o WordList.o
	gcc -o reverse_words main.o mylist.o WordList.o
static: libstatic.a main.o
	gcc -o static main.o -l -lctest
libstatic.a: mylist.o WordList.o
	ar -cvq libstatic.a mylist.o WordList.o && ar -t libstatic.a
shared: libshared.so main.o
	gcc -o shared main.o -L/how-to-put-path
libshared.so: mylistso.o wordlistso.o
	gcc -shared -o libshared.so mylistso.o wordlistso.o
mylistso.o:
	gcc -c -fPIC -o mylstso.o mylist.c
wordlistso.o:
	gcc -c -fPIC -o wordlistso.o wordlist.c       
	
