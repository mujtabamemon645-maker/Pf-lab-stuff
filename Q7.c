#include <stdio.h>

int main()
{
    float sensor_data[3][4];

    // Input data for 3 days and 4 sensors
    printf("Enter temperature data for 3 days and 4 sensors:\n");

    for (int r = 0; r < 3; r++)
    {
        printf("Day %d:\n", r + 1);

        for (int c = 0; c < 4; c++)
        {
            scanf("%f", &sensor_data[r][c]);
        }
    }

    // Ask for defective sensor column
    int index;

    printf("Enter defective sensor column index (0-3): ");
    scanf("%d", &index);

    // Delete column by shifting remaining columns left
    for (int r = 0; r < 3; r++)
    {
        for (int c = index; c < 3; c++)
        {
            sensor_data[r][c] = sensor_data[r][c + 1];
        }
    }

    // Display updated 3x3 matrix
    printf("\nUpdated Sensor Data:\n");

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            printf("%.2f\t", sensor_data[r][c]);
        }

        printf("\n");
    }

    return 0;
}