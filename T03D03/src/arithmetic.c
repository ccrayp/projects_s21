#include <stdio.h>

int sum(int a, int b);
int diff(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main() {
  int a = 0, b = 0;
  char temp = 0;

  if (2 != scanf("%d %d", &a, &b)) {
    printf("Error");
    return 1;
  }
  temp = getchar();
  if (temp != '\n' && temp != EOF) {
    printf("Error");
    return 1;
  }

  printf("%d %d %d ", sum(a, b), diff(a, b), mul(a, b));

  if (b != 0) {
    printf("%d", div(a, b));
  } else {
    printf("n/a");
  }

  return 0;
}

int sum(int a, int b) { return a + b; }

int diff(int a, int b) { return a - b; }

int mul(int a, int b) { return a * b; }

int div(int a, int b) { return a / b; }
