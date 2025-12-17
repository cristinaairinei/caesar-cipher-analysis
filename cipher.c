
#include <stdio.h>
#include <string.h>
#include "cipher.h"
#include "histogram.h"
#include "distance.h"
#include "distribution.h"

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z')
            text[i] = 'a' + (c - 'a' + shift) % 26;
        else if (c >= 'A' && c <= 'Z')
            text[i] = 'A' + (c - 'A' + shift) % 26;
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26 - shift);
}

void break_caesar_cipher(const char *text, int top_shifts[TOP_N], double top_distances[TOP_N], double (*distance_function)(const double[], const double[])) {
    double english_distribution[26];
    read_distribution("distribution.txt", english_distribution);

    double min_distances[TOP_N] = {1e9, 1e9, 1e9};
    int best_shifts[TOP_N] = {0};

    for (int shift = 0; shift < 26; shift++) {
        char shifted_text[strlen(text) + 1];
        strcpy(shifted_text, text);
        decrypt(shifted_text, shift);

        double hist[26];
        compute_histogram(shifted_text, hist);
        double distance = distance_function(hist, english_distribution);

        for (int i = 0; i < TOP_N; i++) {
            if (distance < min_distances[i]) {
                for (int j = TOP_N - 1; j > i; j--) {
                    min_distances[j] = min_distances[j - 1];
                    best_shifts[j] = best_shifts[j - 1];
                }
                min_distances[i] = distance;
                best_shifts[i] = shift;
                break;
            }
        }
    }

    memcpy(top_shifts, best_shifts, sizeof(best_shifts));
    memcpy(top_distances, min_distances, sizeof(min_distances));
}
