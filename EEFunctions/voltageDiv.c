#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "handleInputs.h"

double findVS(double Vi, double Rs, double Ri) {
  return (((Ri + Rs) / Ri) * Vi);
}

double findVI(double Vs, double Rs, double Ri) {
  return ((Ri / (Ri + Rs)) * Vs);
}

double findRS(double Vs, double Vi, double Ri) {
  return (((Ri * Vs) / (Vi)) - Ri);
}

double findRI(double Vs, double Vi, double Rs) {
  return ((Vi * Rs) / (Vs - Vi));
}

double (*vFuncs[4])(double, double, double) = {findVS, findVI, findRS, findRI};

double findVIVS(double *values) {
  // If we have Vs and Vi, compute ratio
  if (*values &&  *(values + 1)) {
    return (*(values + 1) / *(values));
  }

  // Simiarly, if we have Rs and Ri, compute ratio
  if (*(values + 2) && *(values + 3)) {
    return (*(values + 3) / (*(values + 2) + *(values + 3)));
  }

  // If we have 3 parameters, we can find the fourth
  // and update the input array
  double validParams[3] = {0, 0, 0};
  int idx,missing;
  int validIdx = 0;
  int zeroCount = 0;
  for (idx = 0; idx < 4; idx++) {
    if (!(*(values + idx))) {
      // if a V and R value are missing, calculation cannot happen
      if (zeroCount) { return -1; }
      missing = idx;
      zeroCount++;
    } else {
      validParams[validIdx] = *(values + idx);
      validIdx++;
    }
  }

  *(values + missing) = vFuncs[missing](validParams[0],
                                    validParams[1],
                                    validParams[2]);

  return findVIVS(values);

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


  printf("Vi/Vs is determined to be: %f\n", findVIVS(inputs));
  return 0;
}
