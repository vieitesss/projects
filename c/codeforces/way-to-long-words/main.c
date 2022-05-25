#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WLENGTH 101

int main() {
  int w;
  scanf("%d", &w);
  int len = sizeof(char *) * w + sizeof(char) * WLENGTH * w;

  char **words = (char **)malloc(len);
  // pointer to the first element in the 2D array
  char *word = (char *)(words + w);

  // point rows pointer to appropiate location in 2D array
  for (int i = 0; i < w; i++) {
    words[i] = word + WLENGTH * i;
  }

  for (int i = 0; i < w; i++) {
    scanf("%s", words[i]);
  }

  for (int i = 0; i < w; i++) {
    int wlen = strlen(words[i]);
    if (wlen > 10) {
      printf("%c%d%c\n", words[i][0], wlen - 2, words[i][wlen - 1]);
    } else {
      printf("%s\n", words[i]);
    }
  }

  return 0;
}
