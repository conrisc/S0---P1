// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include "gnomes.h"
#include "ioUtils.h"

void *gnome(void *gnomeID) {
  int gID = (long)gnomeID;
  while (true) {
    // sleep(1);
    // randsleep();
    sem_wait(&gnomes);
    if (firstPartNotCreated) {
      createdToy = gID;
      firstPartNotCreated=false;
      cout << "gnome" << gID+1 << "(): Zacząłem robić zabawkę.\n";
      blockedGnome=gID;
      sem_post(&gnomes);
      sem_wait(&gnomeSem[gID]);
    }
    else {
      createdToy+=gID;
      sem_wait(&toyMut);
      toy[createdToy-1]++;
      cout << "gnome" << gID+1 << "(): Skończyłem robić zabawkę.\n"<<buffor();
      bool enoughToys = (toy[0]>=3 && toy[1]>=3 && toy[2]>=3);
      sem_post(&toyMut);

      sem_wait(&santaMut);
      int santaSleeping;
      sem_getvalue(&santaSem, &santaSleeping);
      if (enoughToys && santaSleeping==0) {
        cout << "gnome" << gID+1 << "(): MIKOŁAJ.\n";
        sem_post(&santaSem);
      }
      sem_post(&santaMut);

      firstPartNotCreated = true;
      sem_post(&gnomeSem[blockedGnome]);
      sem_post(&gnomes);
    }
  }
  pthread_exit(NULL);
}
