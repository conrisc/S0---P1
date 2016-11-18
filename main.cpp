// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

using namespace std;

sem_t mutex, e;
int n=0;
int tab[20];

void *gnome1(void *arg) {
  while (true) {
    sem_wait(&e);
    sem_wait(&mutex);
    tab[n]=1;
    n++;
    cout<<tab[n-1]<<endl;
    sem_post(&mutex);
  }
  pthread_exit(NULL);
}

void *gnome2(void *arg) {
  while (true) {
    sem_wait(&e);
    sem_wait(&mutex);
    tab[n]=2;
    n++;
    cout<<tab[n-1]<<endl;
    sem_post(&mutex);
  }
  pthread_exit(NULL);
}

void *gnome3(void *arg) {
  while (true) {
    sem_wait(&e);
    sem_wait(&mutex);
    tab[n]=3;
    n++;
    cout<<tab[n-1]<<endl;
    sem_post(&mutex);
  }
  pthread_exit(NULL);
}


// void santa() {
//   while (true) {
//     semWait(n);
//     semWait(s);
//     take();
//     semSignal(s);
//     semSignal(e);
//     consume();
//   }
// }


int main() {
  sem_init(&mutex,0,1);
  sem_init(&e,0,20);

  pthread_t threads[3];

  pthread_create(&threads[0], NULL, gnome1, NULL);
  pthread_create(&threads[1], NULL, gnome2, NULL);
  pthread_create(&threads[2], NULL, gnome3, NULL);

  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  pthread_join(threads[2], NULL);

   return 0;
}
