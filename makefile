gestaoStock: main.o estado.o acoes.o
	gcc -o gestaoStock main.o estado.o acoes.o 

estado.o: estado.c estado.h
	gcc -c estado.c

acoes.o: acoes.c acoes.h estado.h
	gcc -c acoes.c

main.o: main.c estado.h acoes.h
	gcc -c main.c