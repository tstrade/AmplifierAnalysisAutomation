#include <stdio.h>
#include <string.h>
#include <stdbool.h>

double stringToDouble(char *string) {
  double convertedValue = 0.0;
  int len = strlen(string);
  int i;
  bool decimal = false;
  int divider = 10;

  for (i = 0; i < len; i++) {
    if (string[i] == '.') {
      decimal = true;
      continue;
    }

    if (decimal) {
      convertedValue += (string[i] - '0') / divider;
      divider *= 10;
    } else {
      convertedValue *= 10;
      convertedValue += (string[i] - '0');
    }
  }
  return convertedValue;
}

int encode(double inputs[], int numInputs) {
  int BC = 0;
  int i;
  for (i = 0; i < numInputs; i++) {
    BC += (inputs[i] == 0);
    if (i != (numInputs - 1)) {
      BC *= 10;
    }
  }
  return BC;
}
