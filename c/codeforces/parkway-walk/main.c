#include <stdio.h>
#include <stdlib.h>

#define TN 100
#define ENERGY 10e4

int main() {
  int *cases = malloc(TN * sizeof(int));
  int *benches = malloc(TN * sizeof(int));
  int *energy = malloc(ENERGY * sizeof(int));

  scanf("%d", cases);

  int *spaces;
  for (unsigned int i = 0; i < *cases; i++) {
    scanf("%d %d", benches, energy);
    spaces = realloc(benches, sizeof(int));
    unsigned int j = 0;
    while (fscanf(stdin, " %d", &spaces[j]) == 1 && j < *benches) {
      j++;
    }
    for (int j = 0; j < *benches + 1; j++) {
      printf("%d: %d\n", j, spaces[j]);
    }
  }

  return 0;
}
