// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include "gnomes.h"
#include "santa.h"

sem_t gnomes, gnomeSem[3], santaSem, toyMut;
int blockedGnome, createdToy, toy[3];
bool firstPartNotCreated;

int main() {
  firstPartNotCreated = true;
  sem_init(&toyMut, 0, 1);  //mutex na buffory (wszystkie 3)
  sem_init(&gnomes, 0, 1);
  sem_init(&santaSem, 0, 0);
  sem_init(&gnomeSem[0] ,0, 0);
  sem_init(&gnomeSem[1] ,0, 0);
  sem_init(&gnomeSem[2] ,0, 0);

  pthread_t threads[4];

  for (long i = 0; i < 3; i++) // Trzy gnomy
    pthread_create(&threads[i], NULL, gnome, (void *)i);

  pthread_create(&threads[3], NULL, santa, NULL); // Mikołaj

  for (int i = 0; i < 4; i++)
    pthread_join(threads[i], NULL);

   return 0;
}
