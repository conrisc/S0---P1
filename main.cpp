// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include "gnomes.h"
#include "santa.h"
#include "ioUtils.h"

sem_t gnomes, gnomeSem[3], santaSem, toyMut;
int blockedGnome, createdToy, toy[3];
bool firstPartNotCreated;

int main() {
  firstPartNotCreated = true;
  sem_init(&toyMut, 0, 1);  //mutex na buffory (wszystkie 3)
  sem_init(&gnomes, 0, 1);
  sem_init(&santaSem, 0, 0);
  sem_init(&gnomeSem[0], 0, 0);
  sem_init(&gnomeSem[1], 0, 0);
  sem_init(&gnomeSem[2], 0, 0);

  pthread_t threads[4];

  for (long i = 0; i < 3; i++) {
    toy[i] = 0;

    cout << "main(): Inicjuję gnome" << i+1 << "()..." << endl;
    pthread_create(&threads[i], NULL, gnome, (void *)i);
  }

  cout << "main(): Inicjuję santa()..." << endl;
  pthread_create(&threads[3], NULL, santa, NULL); // Mikołaj

  cout << "main(): Wątki potomne aktywne." << endl << buffor() << flush;

  for (int i = 0; i < 4; i++)
    pthread_join(threads[i], NULL);

   return 0;
}
