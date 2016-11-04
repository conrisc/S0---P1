## Damian Górski, nr indeksu: 273212
## Pracownia z Systemów operacyjnych nr 0: Wątkowy "Hello, world!"

main: main.cpp
	g++ -std=c++11 -Wall -Werror -pthread -c main.cpp 
	g++ -std=c++11 -Wall -Werror -pthread -o main main.o

run: main
	./main

clear:
	rm -rf main.o main
