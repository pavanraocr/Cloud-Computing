disk: diskT1rbs.o
	gcc -O0 -pthread diskT1rbs.o -lm

diskT1rbs.o: diskT1rbs.c
	gcc -c -w diskT1rbs.c

clean:
	rm -f *.o *.txt

run:
	./a.out
