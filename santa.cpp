// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include "santa.h"

void *santa(void *sth) {
  while (true) {
    cout << "santa(): Ho, ho, ho!" << endl;
    sleep(3);   
  }
}
