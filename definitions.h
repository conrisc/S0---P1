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
using namespace std;

extern sem_t gnomes, gnomeSem[3], toyMut;
extern int blockedGnome, createdToy, toy[3];
extern bool firstPartNotCreated;

#endif
