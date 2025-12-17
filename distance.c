
#include <math.h>
#include "distance.h"

double chi_squared_distance(const double hist1[], const double hist2[]) {
    double sum = 0;
    for (int i = 0; i < 26; i++) {
        if (hist2[i] > 0) {
            double diff = hist1[i] - hist2[i];
            sum += (diff * diff) / hist2[i];
        }
    }
    return sum;
}

double euclidean_distance(const double hist1[], const double hist2[]) {
    double sum = 0;
    for (int i = 0; i < 26; i++) {
        double diff = hist1[i] - hist2[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

double cosine_distance(const double hist1[], const double hist2[]) {
    double dot = 0, mag1 = 0, mag2 = 0;
    for (int i = 0; i < 26; i++) {
        dot += hist1[i] * hist2[i];
        mag1 += hist1[i] * hist1[i];
        mag2 += hist2[i] * hist2[i];
    }
    return 1 - (dot / (sqrt(mag1) * sqrt(mag2)));
}
