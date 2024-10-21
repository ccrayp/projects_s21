#include <stdio.h>

int max(int a, int b);

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

  printf("%d", max(a, b));

  return 0;
}

int max(int a, int b) { return a > b ? a : b; }
