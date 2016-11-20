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

      cout << "ZABAWKI [1/2/3]: " << toy[0] << "/" << toy[1] << "/" << toy[2] << endl;

      if (toy[0] >= 3 && toy[1] >= 3 && toy[2] >= 3) {
        cout << "gnome" << gID+1 << "(): Czas dać znać Mikołajowi, że zebraliśmy zabawki." << endl;
        sem_post(&santaSem);
      }

      sem_post(&gnomeSem[blockedGnome]);
      sem_post(&gnomes);
    }
  }
}
