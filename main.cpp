// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

using namespace std;

sem_t gnomes, gnomeSem[3],santaSem, toyMut;
int blockedGnome, createdToy, toy[3];
bool firstPartNotCreated=true;

void *gnome(void *gnomeID) {
  int gID = (long)gnomeID;
  while (true) {
    // sleep(1);
    sem_wait(&gnomes);
    // cout<<gID<<":\n";
    if(firstPartNotCreated) {
      createdToy=gID;
      firstPartNotCreated=false;
      cout<<gID<<" Stworzylem pierwsza czesc\n";
      blockedGnome=gID;
      sem_post(&gnomes);
      sem_wait(&gnomeSem[gID]);
    }
    else {
      createdToy+=gID;
      sem_wait(&toyMut);
      toy[createdToy-1]++;
      cout<<gID<<" Dokonczylem tworzyc zabawke\n";
      cout<<  "BUFFOR "<<createdToy<<": "<<toy[createdToy-1]<<endl;
      sem_post(&toyMut);
      firstPartNotCreated=true;
      sem_post(&gnomeSem[blockedGnome]);
      sem_post(&gnomes);
    }
  }
}

void *santa(void *sth) {
  while (true) {
    sem_wait(&santaSem);

    sem_wait(&toyMut);
    cout << "\rsanta(): Zabawki się uzbierały, wstaję do pracy..." << endl << flush;

    for (int i = 0; i < 3; i++)
      toy[i] -= 3;

    cout << "\rsanta(): I po robocie, zabawki wysłane. Czas iść spać..." << flush;
    sem_post(&toyMut);
  }
  pthread_exit(NULL);
}

int main() {
  sem_init(&toyMut,0,1);  //mutex na buffory (wszystkie 3)
  sem_init(&gnomes,0,1);
  sem_init(&santaSem, 0, 0);
  sem_init(&gnomeSem[0],0,0);
  sem_init(&gnomeSem[1],0,0);
  sem_init(&gnomeSem[2],0,0);

  pthread_t threads[3];

  pthread_create(&threads[3], NULL, santa, NULL);

  for (long i=0;i<3;i++)
    pthread_create(&threads[i], NULL, gnome, (void *)i);



  for (int i=0;i<3;i++)
    pthread_join(threads[i], NULL);

   return 0;
}
