// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#ifndef DEFINITIONS_INCLUDED
#define DEFINITIONS_INCLUDED

#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <string>
using namespace std;

extern string buffor();

extern sem_t gnomes, gnomeSem[3], santaSem, toyMut;
extern int blockedGnome, createdToy, toy[3];
extern bool firstPartNotCreated, santaSleeping;

#endif
