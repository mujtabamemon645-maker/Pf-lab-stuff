#include <stdio.h>
#include <string.h>

int main() {
    // 1. Create a 2D array where each row holds a line of 3 space-separated words
    char word_grid[3][100];
    
    char longest_word[100] = "";
    int max_length = 0;
    int best_row_index = -1;

    printf("Word Grid Analyzer\n");
    printf("===========================================\n");
    printf("Please enter 3 words per line (e.g., \"cat elephant dog\"):\n\n");

    // 2. Read each line from the user using the Scanset %[^\n]
    for (int i = 0; i < 3; i++) {
        printf("Enter line %d: ", i + 1);
        
        // The space before %99[^\n] automatically clears out leftover newline tokens
        scanf(" %99[^\n]", word_grid[i]);
    }

    // 3. Write Nested Loops to tokenize/parse words from each row and calculate lengths
    // Outer loop iterates through each message row
    for (int i = 0; i < 3; i++) {
        char current_word[100];
        int char_idx = 0;

        // Inner loop traverses the characters of the row to isolate separate words manually
        for (int j = 0; word_grid[i][j] != '\0'; j++) {
            // Check if current character is a spacing separator or an end marker
            if (word_grid[i][j] != ' ') {
                current_word[char_idx++] = word_grid[i][j];
            }
            
            // When hitting a space or looking at the last character before the null terminator
            if (word_grid[i][j] == ' ' || word_grid[i][j + 1] == '\0') {
                if (char_idx > 0) {
                    current_word[char_idx] = '\0'; // Properly close string token
                    int current_length = strlen(current_word);

                    // 4. Identify the word with the maximum length and track its Row Index (i)
                    if (current_length > max_length) {
                        max_length = current_length;
                        strcpy(longest_word, current_word);
                        best_row_index = i;
                    }
                    
                    char_idx = 0; // Reset string array position index for next word
                }
            }
        }
    }

    // Output the final results
    printf("\n===========================================\n");
    printf("ANALYSIS REPORT\n");
    printf("===========================================\n");
    if (max_length > 0) {
        printf("Longest Word Found : \"%s\"\n", longest_word);
        printf("Character Length   : %d letters\n", max_length);
        printf("Located at Row (i) : %d (Line %d)\n", best_row_index, best_row_index + 1);
    } else {
        printf("No valid words found.\n");
    }
    printf("===========================================\n");

    return 0;
}
