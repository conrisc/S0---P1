// Konrad Cielecki, nr indeksu: 273278
// Damian Górski, nr indeksu: 273212
// Pracownia z Systemów operacyjnych nr 1: Problem synchronizacji wątków

#include "ioUtils.h"

void randsleep() {
  int random = rand() % 32 + 16;
  usleep(random);
}

string buffor() {
  if (toy[0] < 0 || toy[1] < 0 || toy[2] < 0) {
    string foo = "ERROR";
    for (int i = 0; i < 30; i++) foo += "\nERROR";
    return foo;
  }
  else return (  
    "ZABAWKI NA SKŁADZIE: [" +
      string("Z1: ") + to_string(toy[0]) + 
      string("  |  Z2: ") + to_string(toy[1]) +
      string("  |  Z3: ") + to_string(toy[2]) + 
    "]"
  );
}
