#include <stdio.h>
#include <string.h>
#include "cipher.h"
#include "histogram.h"
#include "distribution.h"
#include "distance.h"

void show_menu() {
    int choice;
    char text[256] = "";
    int shift;
    int top_shifts[TOP_N];
    double top_distances[TOP_N];

    do {
        printf("\n===== Caesar Cipher Menu =====\n");
        printf("1. Enter text\n");
        printf("2. Encrypt text\n");
        printf("3. Decrypt text\n");
        printf("4. Compute letter frequency histogram\n");
        printf("5. Break Caesar cipher\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter text: ");
                fgets(text, 256, stdin);
                text[strcspn(text, "\n")] = '\0';
                break;
            case 2:
                printf("Enter shift: ");
                scanf("%d", &shift);
                getchar();
                encrypt(text, shift);
                printf("Encrypted: %s\n", text);
                break;
            case 3:
                printf("Enter shift: ");
                scanf("%d", &shift);
                getchar();
                decrypt(text, shift);
                printf("Decrypted: %s\n", text);
                break;
            case 4: {
                double hist[ALPHABET_SIZE];
                compute_histogram(text, hist);
                printf("Letter frequencies:\n");
                for (int i = 0; i < ALPHABET_SIZE; i++) {
                    printf("%c: %.4f\n", 'a' + i, hist[i]);
                }
                break;
            }
            case 5:
                break_caesar_cipher(text, top_shifts, top_distances, chi_squared_distance);
                printf("Most likely shift: %d\n", top_shifts[0]);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
}
