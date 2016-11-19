// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

using namespace std;

sem_t gnomeSem[3], toyMut, toyS[3], gnomes;
int blockedGnome;
int createdToy;
bool firstPartNotCreated=true;
int n[3];
bool toy[3][30];

int temp;

void *gnome1(void *arg) {
  while (true) {
    sleep(2);
    sem_wait(&gnomes);
    cout<<"1:\n";
    if(firstPartNotCreated) {
      createdToy=0;
      firstPartNotCreated=false;
      cout<<"  1 Stworzylem pierwsza czesc\n";
      blockedGnome=0;
      sem_post(&gnomes);
      sem_wait(&gnomeSem[0]);
    }
    else {
      createdToy+=0;
      sem_wait(&toyMut);
      // toy[createdToy-1][1]=true;
      // n[createdToy-1]++;
      sem_post(&toyMut);
      firstPartNotCreated=true;
      cout<<"  1 Dokonczylem tworzyc zabawke\n";
      sem_post(&gnomeSem[blockedGnome]);
      sem_post(&gnomes);
    }
  }
}

void *gnome2(void *arg) {
  sleep(1);
  while (true) {
    sleep(2);
    sem_wait(&gnomes);
    cout<<"2:\n";
    if(firstPartNotCreated) {
      createdToy=1;
      firstPartNotCreated=false;
      cout<<"  2 Stworzylem pierwsza czesc\n";
      blockedGnome=1;
      sem_post(&gnomes);
      sem_wait(&gnomeSem[1]);
    }
    else {
      createdToy+=1;
      sem_wait(&toyMut);
      toy[createdToy-1][1]=true;
      n[createdToy-1]++;
      sem_post(&toyMut);
      firstPartNotCreated=true;
      cout<<"  2 Dokonczylem tworzyc zabawke\n";
      sem_post(&gnomeSem[blockedGnome]);
      sem_post(&gnomes);
    }
  }
}

void *gnome3(void *arg) {
  sleep(2);
  while (true) {
    sleep(2);
    sem_wait(&gnomes);
    cout<<"3:\n";
    if(firstPartNotCreated) {
      createdToy=1;
      firstPartNotCreated=false;
      cout<<"  3 Stworzylem pierwsza czesc\n";
      blockedGnome=2;
      sem_post(&gnomes);
      sem_wait(&gnomeSem[2]);
    }
    else {
      createdToy+=1;
      sem_wait(&toyMut);
      toy[createdToy-1][1]=true;
      n[createdToy-1]++;
      sem_post(&toyMut);
      firstPartNotCreated=true;
      cout<<"  3 Dokonczylem tworzyc zabawke\n";
      sem_post(&gnomeSem[blockedGnome]);
      sem_post(&gnomes);
    }
  }
}

int main() {
  sem_init(&toyMut,0,1);  //mutex na buffory (wszystkie 3)
  sem_init(&gnomes,0,1);
  sem_init(&gnomeSem[0],0,0);
  sem_init(&gnomeSem[1],0,0);
  sem_init(&gnomeSem[2],0,0);
  sem_init(&toyS[0],0,30);
  sem_init(&toyS[1],0,30);
  sem_init(&toyS[2],0,30);

  pthread_t threads[3];

  pthread_create(&threads[0], NULL, gnome1, NULL);
  pthread_create(&threads[1], NULL, gnome2, NULL);
  pthread_create(&threads[2], NULL, gnome3, NULL);

  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  pthread_join(threads[2], NULL);

   return 0;
}
