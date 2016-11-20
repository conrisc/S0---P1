## Konrad Cielecki, nr indeksu: 273278
## Damian Górski, nr indeksu: 273212
## Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

main: main.cpp
	g++ -std=c++11 -Wall -Werror -pthread -c main.cpp gnomes.cpp santa.cpp
	g++ -std=c++11 -Wall -Werror -pthread -o main main.o gnomes.o santa.o

run: main
	./main

clear:
	rm -rf main main.o gnomes.o santa.o
