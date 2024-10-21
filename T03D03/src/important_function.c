#include <math.h>
#include <stdio.h>

float func(float x);

int main() {
  float x = 0.0;
  int res1 = scanf("%f", &x);

  char temp;
  temp = getchar();
  if (temp != '\n' && temp != EOF) {
    printf("Error");
    return 1;
  }

  if (res1 == 1)
    printf("%.1f", func(x));

  return 0;
}

float func(float x) {
  return 7e-3 * pow(x, 4) +
         ((22.8 * pow(x, 1 / 3) - 1e3) * x + 3) / (x * x / 2) -
         x * pow((10 + x), (2 / x)) - 1.01;
}
