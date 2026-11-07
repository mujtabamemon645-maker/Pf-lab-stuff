#include <stdio.h>

// User-defined function to print sensor data using void pointer
void printSensorData(void *dataPtr, char dataType) {
    if (dataType == 'f' || dataType == 'F') {
        // Cast void pointer to float pointer and dereference
        float temp = *(float *)dataPtr;
        printf("Temperature Sensor: %.2f °C\n", temp);
    } 
    else if (dataType == 'i' || dataType == 'I') {
        // Cast void pointer to int pointer and dereference
        int motion = *(int *)dataPtr;
        if (motion == 1) {
            printf("Motion Sensor: Motion Detected\n");
        } else if (motion == 0) {
            printf("Motion Sensor: No Motion\n");
        } else {
            printf("Motion Sensor: Invalid Status\n");
        }
    } 
    else if (dataType == 'c' || dataType == 'C') {
        // Cast void pointer to char pointer and dereference
        char doorStatus = *(char *)dataPtr;
        if (doorStatus == 'O' || doorStatus == 'o') {
            printf("Door Lock Sensor: Door Open\n");
        } else if (doorStatus == 'C' || doorStatus == 'c') {
            printf("Door Lock Sensor: Door Closed\n");
        } else {
            printf("Door Lock Sensor: Invalid Status\n");
        }
    } 
    else {
        printf("Unknown Sensor Data Type!\n");
    }
}

int main() {
    // 1. Declare variables for temperature, motion status, and door lock status
    float temperature = 24.5;
    int motionStatus = 1;     // 1 for Motion Detected, 0 for No Motion
    char doorStatus = 'O';    // 'O' for Open, 'C' for Closed

    printf("--- Smart Home IoT Controller ---\n");

    // 2. Pass addresses along with appropriate data type characters to printSensorData()
    printSensorData(&temperature, 'f');
    printSensorData(&motionStatus, 'i');
    printSensorData(&doorStatus, 'c');

    return 0;
}