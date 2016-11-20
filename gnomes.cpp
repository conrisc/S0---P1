// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include "gnomes.h"

void *gnome(void *gnomeID) {
  int gID = (long)gnomeID;
  while (true) {
    sleep(1);
    sem_wait(&gnomes);
    // cout<<gID<<":\n";
    if (firstPartNotCreated) {
      createdToy = gID;
      firstPartNotCreated=false;
      cout << "gnome" << gID+1 << "(): Zacząłem robić zabawkę. Czekam, aż ktoś ją dokończy." << endl;
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
      cout << "gnome" << gID+1 << "(): Skończyłem robić zabawkę skrzata " << tmp+1 
           << ". Odłożyłem nową zabawkę " << createdToy << "." << endl;
      cout << "BUFFOR " << createdToy << ": "<< toy[createdToy-1] << endl;      
      sem_post(&gnomeSem[blockedGnome]);
      sem_post(&gnomes);
    }
  }
}
