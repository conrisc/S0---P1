// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include "santa.h"
#include "ioUtils.h"

void *santa(void *sth) {
  while (true) {
    sem_wait(&santaSem);
   
    sem_wait(&toyMut);
    cout << "\rsanta(): Zabawki się uzbierały, wstaję do pracy..." << endl << buffor() << flush;

    sleep(3);

    for (int i = 0; i < 3; i++)
      toy[i] -= 3;

    cout << "\rsanta(): I po robocie, zabawki wysłane. Czas iść spać..." << endl << buffor() << flush;
    sem_post(&toyMut);
  }
  pthread_exit(NULL);
}
