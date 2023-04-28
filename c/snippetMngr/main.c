#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char output[1024];

    fp = popen("lsof | grep REG | grep \"/User/\"", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        exit(1);
    }

    while (fgets(output, sizeof(output), fp) != NULL) {
        printf("%s", output);
    }

    pclose(fp);

    return EXIT_SUCCESS;
}
