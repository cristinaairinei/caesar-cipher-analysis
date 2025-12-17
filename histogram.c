
#include <string.h>
#include "histogram.h"

void compute_histogram(const char *text, double histogram[26]) {
    int total = 0;
    memset(histogram, 0, 26 * sizeof(double));

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            histogram[c - 'a']++;
            total++;
        } else if (c >= 'A' && c <= 'Z') {
            histogram[c - 'A']++;
            total++;
        }
    }

    if (total > 0) {
        for (int i = 0; i < 26; i++) {
            histogram[i] /= total;
        }
    }
}

