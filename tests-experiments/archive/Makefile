.PHONY: clean

main.exe: main.o square.o
	gcc main.o square.o -o main.exe -g

%.o: %.c main.h
	gcc -c $< -o $@ -g

clean:
	del main.o square.o main.exe