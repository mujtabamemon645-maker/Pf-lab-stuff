#include <stdio.h>

int main() {
    // 1. Declare a 2D string array to store 3 encrypted lines of text
    char secret_messages[3][100];
    int word_counts[3] = {0};

    printf("Intelligence Agency Secure Messaging Portal\n");
    printf("===========================================\n");
    printf("Note: Input will automatically truncate if a number or symbol is entered.\n\n");

    // Loop to read 3 messages
    for (int i = 0; i < 3; i++) {
        printf("Enter secret message %d: ", i + 1);

        // 2. Read user input using Validation Scanset %[A-Z ]
        // The space inside the brackets allows spaces, while A-Z allows capital letters.
        // A leading space in the format string handles leftover newlines in the input buffer.
        scanf(" %99[A-Z ]", secret_messages[i]);

        // Clear the remaining input buffer in case truncation happened
        // This ensures the next loop iteration doesn't read the rejected characters
        while (getchar() != '\n');

        // 3. Using Nested Loops to count spaces and calculate word count
        int space_count = 0;
        int has_characters = 0;

        // Inner loop traverses the string character-by-character up to the null terminator
        for (int j = 0; secret_messages[i][j] != '\0'; j++) {
            has_characters = 1; // Mark that the string isn't completely empty
            
            if (secret_messages[i][j] == ' ') {
                space_count++;
            }
        }

        // Determine the number of words based on spaces
        if (has_characters > 0) {
            word_counts[i] = space_count + 1;
        } else {
            word_counts[i] = 0;
        }
    }

    // 4. Display the filtered messages and their respective word counts
    printf("\n===========================================\n");
    printf("FILTERED INTELLIGENCE REPORT\n");
    printf("===========================================\n");
    for (int i = 0; i < 3; i++) {
        printf("Message %d: \"%s\"\n", i + 1, secret_messages[i]);
        printf("Word Count: %d\n", word_counts[i]);
        printf("-------------------------------------------\n");
    }

    return 0;
}

