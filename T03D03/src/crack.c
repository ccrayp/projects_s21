#include <math.h>
#include <stdio.h>

int main() {
  float x = 0.0, y = 0;
  char temp = 0;

  if (2 != scanf("%f %f", &x, &y)) {
    printf("Error");
    return 1;
  }
  temp = getchar();
  if (temp != '\n' && temp != EOF) {
    printf("Error");
    return 1;
  }

  if (pow(x, 2) + pow(y, 2) < 25)
    printf("GOTCHA");
  else
    printf("MISS");

  return 0;
}
