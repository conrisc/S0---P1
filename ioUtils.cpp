// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include "ioUtils.h"

void randsleep() {
  int random = rand() % 800000 + 400000;
  usleep(random);
}

string buffor() {
  return (
   " [" +
       to_string(toy[0]) +
       string("  |  ") + to_string(toy[1]) +
       string("  |  ") + to_string(toy[2]) +
    "]\n"
  );
}
