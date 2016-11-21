// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include "gnomes.h"
#include "ioUtils.h"

void *gnome(void *gnomeID) {
  int gID = (long)gnomeID;
  while (true) {
    // sleep(1);
    randsleep();
    sem_wait(&gnomes);
    // cout<<gID<<":\n";
    if (firstPartNotCreated) {
      createdToy = gID;
      firstPartNotCreated=false;
      cout << "\rgnome" << gID+1 << "(): Zacząłem robić zabawkę. Czekam, aż ktoś ją dokończy." << endl << buffor() << flush;
      blockedGnome=gID;
      sem_post(&gnomes);
      sem_wait(&gnomeSem[blockedGnome]);
    }
    else {
      int tmp = createdToy;
      createdToy+=gID;
      sem_wait(&toyMut);
      toy[createdToy-1]++;
      sem_post(&toyMut);
      firstPartNotCreated = true;
      cout << "\rgnome" << gID+1 << "(): Skończyłem robić zabawkę skrzata " << tmp+1 
           << ". Odłożyłem nową zabawkę " << createdToy << "." << endl << buffor() << flush;

      if (toy[0] >= 3 && toy[1] >= 3 && toy[2] >= 3) {
        cout << "\rgnome" << gID+1 << "(): Czas dać znać Mikołajowi, że zebraliśmy zabawki." << endl << buffor() << flush;
        sem_post(&santaSem);
      }

      sem_post(&gnomeSem[blockedGnome]);
      sem_post(&gnomes);
    }
  }
  pthread_exit(NULL);
}
