#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000
#define ll long long

ll createPalindrome(const long n) {
  char number[MAX];

  sprintf(number, "%ld", n);

  ll l = strlen(number);
  ll i, j;

  number[l - 1] = number[0];
  for (i = 1, j = l - 2; i < l / 2; i++, l--) {
    number[i] = '9';
    number[j] = '9';
  }

  if (l > 1 && l % 2 != 0) {
    number[l / 2] = '9';
  }

  return (ll)atoi(number);
}

int main() {
  int cases;
  scanf("%d", &cases);

  long long l, n, min;
  for (int i = 0; i < cases; i++) {
    scanf("%lld", &l);
    scanf("%lld", &n);

    min = pow(10, l - 1) + n;

    printf("%lld\n", createPalindrome(min) - n);
  }
  return 0;
}
