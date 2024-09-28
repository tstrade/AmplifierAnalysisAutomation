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

double findVSVI(double values[]) {
  double params[3] = {0, 0, 0};
  int i,f;
  int j = 0;
  for (i = 0; i < 4; i++) {
    if (!values[i]) {
      f = i;
    } else {
      params[j] = values[i];
      j++;
    }
  }
  values[f] = vFuncs[f](params[0],params[1],params[2]);

  if (values[0] &&  values[1]) {
    return (values[0] / values[1]);
  } else {
    return (values[2] / (values[2] + values[3]));
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


  printf("Vs/Vi is determined to be: %f\n", findVSVI(inputs));
  return 0;
}
