## Konrad Cielecki, nr indeksu: 273278
## Damian Górski, nr indeksu: 273212
## Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

main: main.cpp
	g++ -std=c++11 -Wall -Werror -pthread -c main.cpp gnomes.cpp santa.cpp ioUtils.cpp
	g++ -std=c++11 -Wall -Werror -pthread -o main main.o gnomes.o santa.o ioUtils.o

run: main
	./main

clean:
	rm -rf main.o gnomes.o santa.o ioUtils.o

distclean:
	rm -rf main main.o gnomes.o santa.o ioUtils.o
