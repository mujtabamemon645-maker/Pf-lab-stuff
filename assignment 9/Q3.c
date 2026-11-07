#include <stdio.h>

int main() {
    int image[3][3];
    int (*ptr)[3] = image; // Pointer to an array of three integers

    printf("Enter values for the 3x3 image matrix (9 pixels):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Using pointer arithmetic exclusively to read input
            scanf("%d", (*(ptr + i) + j));
        }
    }

    // Multiply each pixel value by 2 using pointer arithmetic exclusively
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(*(ptr + i) + j) *= 2;
        }
    }

    printf("\nUpdated 3x3 Image Matrix (Brightness Doubled):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", *(*(ptr + i) + j));
        }
        printf("\n");
    }

    return 0;
}