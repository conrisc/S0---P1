// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include "gnomes.h"
#include "ioUtils.h"

void *gnome(void *gnomeID) {
  int gID = (long)gnomeID;
  while (true) {
    randsleep();
    sem_wait(&gnomes);
    if (firstPartNotCreated) {
      createdToy = gID;
      firstPartNotCreated=false;
      cout << "gnome" << gID+1 << "(): Zacząłem produkcję zabawki.\n";
      blockedGnome=gID;
      sem_post(&gnomes);
      sem_wait(&gnomeSem[gID]);
    }
    else {
      createdToy+=gID;
      sem_wait(&toyMut);
      toy[createdToy-1]++;
      cout << "gnome" << gID+1 << "(): Skończyłem produkcję zabawki (" << createdToy << ").\n" << buffor();
      bool enoughToys = (toy[0] >= 3 && toy[1] >= 3 && toy[2] >= 3);

      if (enoughToys && santaSleeping) {
        cout << "gnome" << gID+1 << "(): Budzę Mikołaja.\n";
        santaSleeping = false;
        sem_post(&santaSem);
      }

      sem_post(&toyMut);

      firstPartNotCreated = true;
      sem_post(&gnomeSem[blockedGnome]);
      sem_post(&gnomes);
    }
  }
  pthread_exit(NULL);
}
