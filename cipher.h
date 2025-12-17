
#ifndef CIPHER_H
#define CIPHER_H

#define TOP_N 3

void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
void break_caesar_cipher(const char *text, int top_shifts[TOP_N], double top_distances[TOP_N], double (*distance_function)(const double[], const double[]));

#endif
