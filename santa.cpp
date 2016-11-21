// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include "santa.h"
#include "ioUtils.h"

void *santa(void *sth) {
  while (true) {
    sem_wait(&santaSem);
    sem_wait(&toyMut);
    cout << "santa(): Zabawki się uzbierały, wstaję do pracy...\n";

    sleep(3);

    for (int i = 0; i < 3; i++)
      toy[i] -= 3;

    cout << "santa(): Zabawki wysłane. Czas iść spać...\n" << buffor();
    santaSleeping = true;
    sem_post(&toyMut);
  }
  pthread_exit(NULL);
}
