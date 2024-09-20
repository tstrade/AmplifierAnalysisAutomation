#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "handleInputs.h"

double findVI(double Vs, double Rs, double Ri) {
  return ((Ri / (Ri + Rs)) * Vs);
}

double findVS(double Vi, double Rs, double Ri) {
  return (((Ri + Rs) / Ri) * Vi);
}

double findRS(double Vs, double Vi, double Ri) {
  return (((Ri * Vs) / (Vi)) - Ri);
}

double findRI(double Vs, double Vi, double Rs) {
  return ((Vi * Rs) / (Vs - Vi));
}

double findVIVS(double Vs, double Vi, double Rs, double Ri) {
  if (!Vi || !Vs) {
    return (Vi / Vs);
  } else {
    return (Ri / (Ri + Rs));
  }
}
