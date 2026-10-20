#include <stdio.h>

int main() {
    // 3. Store these fields across a 2D character array char logs[3][30].
    // logs[0] = username, logs[1] = status, logs[2] = timestamp
    char logs[3][30];
    int uppercase_count = 0;

    // 1. Prompt the user to enter 3 CSV log entries.
    printf("Cybersecurity Log Monitoring System Parser\n");
    printf("==========================================\n");
    printf("Example entry format: Admin_User,Access Granted,10:45AM\n\n");

    for (int entry = 1; entry <= 3; entry++) {
        printf("Enter log entry #%d: ", entry);

        // 2. Use a single scanf statement with Negated Scanset %[^,] to split each log entry
        // %29[^,] captures up to 29 chars before a comma.
        // %29[^\n] captures the remaining field up until the enter key.
        // The space at the start of the format string skips over any leftover whitespace/newlines.
        int fields_parsed = scanf(" %29[^,],%29[^,],%29[^\n]", logs[0], logs[1], logs[2]);

        // Error checking to verify full line structure matched
        if (fields_parsed != 3) {
            printf("Error: Parsing failed. Please ensure the CSV is properly formatted with 2 commas.\n");
            return 1;
        }

        // 4. Using Nested Loops, iterate character-by-character through all stored strings
        // Outer loop: Travels through the 3 extracted string buffers
        for (int i = 0; i < 3; i++) {
            // Inner loop: Inspects each character index sequentially until the Null Terminator ('\0')
            for (int j = 0; logs[i][j] != '\0'; j++) {
                // Count the total number of uppercase letters (A-Z)
                if (logs[i][j] >= 'A' && logs[i][j] <= 'Z') {
                    uppercase_count++;
                }
            }
        }
        
        printf("-> Entry #%d parsed successfully!\n\n", entry);
    }

    // Print the final aggregated count
    printf("==========================================\n");
    printf("Total uppercase letters (A-Z) across all 3 log matrices: %d\n", uppercase_count);
    printf("==========================================\n");

    return 0;
}
