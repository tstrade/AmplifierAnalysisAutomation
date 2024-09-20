#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "voltageDiv.h"
#include "handleInputs.h"

// static int BCT[5] = {0,1,2,4,8};

bool eliminate(int BC) {
  return BC || 0;
}

double findRatio(int BC, double inputs[]) {
  double VIVS1,VIVS2;
  switch (BC) {
  case 0:
    VIVS1 = findVIVS(inputs[0], inputs[1], 0, 0);
    VIVS2 = findVIVS(0, 0, inputs[2], inputs[3]);
    return ((VIVS1 + VIVS2) / 2);
  case 1:
    double VS = findVS(inputs[1], inputs[2], inputs[3]);
    VIVS1 = findVIVS(VS, inputs[1], 0, 0);
    VIVS2 = findVIVS(0, 0, inputs[2], inputs[3]);
    return ((VIVS1 + VIVS2) / 2);
  case 2:
    double VI = findVI(inputs[0], inputs[2], inputs[3]);
    VIVS1 = findVIVS(VI, inputs[1], 0, 0);
    VIVS2 = findVIVS(0, 0, inputs[2], inputs[3]);
    return ((VIVS1 + VIVS2) / 2);
  case 4:
    double RS = findRS(inputs[0], inputs[1], inputs[3]);
    VIVS1 = findVIVS(inputs[0], inputs[1], 0, 0);
    VIVS2 = findVIVS(0, 0, RS, inputs[3]);
    return ((VIVS1 + VIVS2) / 2);
  case 8:
    double RI = findRI(inputs[0], inputs[1], inputs[2]);
    VIVS1 = findVIVS(inputs[0], inputs[1], 0, 0);
    VIVS2 = findVIVS(0, 0, inputs[2], RI);
    return ((VIVS1 + VIVS2) / 2);
  default:
    bool found = eliminate(BC);
    if (found) {
      return findVIVS(inputs[0], inputs[1], inputs[2], inputs[3]);
    } else {
      return -1;
    }
  }
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
