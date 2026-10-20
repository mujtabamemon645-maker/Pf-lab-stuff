#include <stdio.h>

int main() {
    // a. Declare a 2D character array to store full names of 3 students (max 49 characters + null terminator)
    char student_names[3][50];
    
    // b. Declare a 2D integer array to store 3 subject marks for each student
    int marks[3][3];
    
    // Array to store calculated averages for the final report
    float averages[3];

    // Loop through each student to gather their details
    for (int i = 0; i < 3; i++) {
        printf("--- Entering details for Student %d ---\n", i + 1);
        
        // c. Use Negated Scanset %[^\n] to input multi-word names
        printf("Enter full name: ");
        scanf("%49[^\n]", student_names[i]);
        
        // d. i. Use Nested Loops to input 3 subject marks for each student
        int total_marks = 0;
        for (int j = 0; j < 3; j++) {
            printf("Enter marks for Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
            total_marks += marks[i][j];
        }
        
        // Calculate the average marks for the current student
        averages[i] = total_marks / 3.0;

        // Clear the input buffer (removes the trailing newline character '\n')
        // This prevents the next name input from being skipped.
        while (getchar() != '\n'); 
        printf("\n");
    }

    // e. Display each student's average marks alongside their full name in a formatted report
    printf("==================================================\n");
    printf("%-30s %s\n", "STUDENT FULL NAME", "AVERAGE MARKS");
    printf("==================================================\n");
    for (int i = 0; i < 3; i++) {
        printf("%-30s %.2f\n", student_names[i], averages[i]);
    }
    printf("==================================================\n");

    return 0;
}
