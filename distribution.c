#include <stdio.h>
#include "distribution.h"

void read_distribution(const char *filename, double distribution[ALPHABET_SIZE]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        fscanf(file, "%lf", &distribution[i]);
    }
    fclose(file);
}
