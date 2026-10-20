#include <stdio.h>

int main()
{
    int shifts[4][3];

    // Input initial 3x3 matrix
    printf("Enter production data for 3 workstations:\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Workstation %d: ", i);

        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &shifts[i][j]);
        }
    }

    // Input target row index
    int index;

    printf("Enter row index for insertion (0-3): ");
    scanf("%d", &index);

    // Input new row
    printf("Enter 3 production values for the new row:\n");

    int newRow[3];

    for (int j = 0; j < 3; j++)
    {
        scanf("%d", &newRow[j]);
    }

    // Shift existing rows downward
    for (int i = 3; i > index; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            shifts[i][j] = shifts[i - 1][j];
        }
    }

    // Insert new row
    for (int j = 0; j < 3; j++)
    {
        shifts[index][j] = newRow[j];
    }

    // Display resulting 4x3 matrix
    printf("\nResulting Matrix:\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", shifts[i][j]);
        }

        printf("\n");
    }

    return 0;
}