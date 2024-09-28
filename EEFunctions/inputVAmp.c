#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "voltageDiv.h"
#include "handleInputs.h"

// static int BCT[5] = {0,1,2,4,8};

bool eliminate(int BC) {
  return BC || 0;
}

double findRatio(double inputs[]) {
  return findVSVI(inputs);
}

int main(int argv, char *argc[]) {
  if (argv != 5) {
    printf("Invalid arguments.\n");
    return -1;
  }
  double inputs[4] = {stringToDouble(argc[1]),
                      stringToDouble(argc[2]),
                      stringToDouble(argc[3]),
                      stringToDouble(argc[4])};

  int BC = encode(inputs, 4);
  double VIVS = findRatio(BC, inputs);

  printf("Vi/Vs is determined to be: %f\n", VIVS);
  return 0;
}
