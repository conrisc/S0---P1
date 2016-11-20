// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include "gnomes.h"

sem_t gnomes, gnomeSem[3], toyMut;
int blockedGnome, createdToy, toy[3];
bool firstPartNotCreated;

int main() {
  sem_init(&toyMut, 0, 1);  //mutex na buffory (wszystkie 3)
  sem_init(&gnomes, 0, 1);
  sem_init(&gnomeSem[0] ,0, 0);
  sem_init(&gnomeSem[1] ,0, 0);
  sem_init(&gnomeSem[2] ,0, 0);

  pthread_t threads[3];

  for (long i = 0; i < 3; i++)
    pthread_create(&threads[i], NULL, gnome, (void *)i);

  for (int i = 0; i < 3; i++)
    pthread_join(threads[i], NULL);

   return 0;
}
