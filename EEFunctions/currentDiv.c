#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "handleInputs.h"

double currentDivision(double Is, double Rs, double Ri) {
  return ((Rs / (Ri + Rs)) * Is);
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Invalid input.\n");
    return -1;
  }

  double Is = stringToDouble(argv[1]);
  double Rs = stringToDouble(argv[2]);
  double Ri = stringToDouble(argv[3]);
  double Ii = currentDivision(Is, Rs, Ri);

  printf("Input current: %f A\n", Ii);

  return 0;
}
