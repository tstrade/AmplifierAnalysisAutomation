#include <string.h>

double stringToDouble(char *string) {
  double convertedValue = 0.0;
  int len = strlen(string);
  int i;
  int decimal = 0;
  int divider = 10;

  for (i = 0; i < len; i++) {
    if (string[i] == '.') {
      decimal = 1;
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
