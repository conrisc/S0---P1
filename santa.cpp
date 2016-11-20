// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include "santa.h"

void *santa(void *sth) {
  while (true) {
    sem_wait(&santaSem);
   
    sem_wait(&toyMut);
    cout << "santa(): Zabawki się uzbierały, wstaję do pracy..." << endl;
    
    for (int i = 0; i < 3; i++)
      toy[i] -= 3;

    sleep(3);

    cout << "santa(): I po robocie. Czas iść spać..." << endl;
    cout << "ZABAWKI [1/2/3]: " << toy[0] << "/" << toy[1] << "/" << toy[2] << endl;
    sem_post(&toyMut);
  }
}
