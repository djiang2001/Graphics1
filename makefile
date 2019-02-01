all:
	gcc -o pic main.c
	./pic

clean:
	rm *.o
