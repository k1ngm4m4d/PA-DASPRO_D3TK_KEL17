#include <stdio.h>
#include <string.h>

// Function to perform CRC calculation
void calculateCRC(char* data, int dataLength, char* divisor, int divisorLength) {
    // Append zeros to data based on divisor length
    for (int i = 0; i < divisorLength - 1; i++) {
        strcat(data, "0");
    }

    int dataSize = strlen(data);

    // Perform CRC calculation
    for (int i = 0; i < dataSize - divisorLength + 1; i++) {
        if (data[i] == '1') {
            // XOR operation
            for (int j = 0; j < divisorLength; j++) {
                data[i + j] = (data[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }
}

int main() {
    char data[] = "10110011";  // Example data in binary
    char divisor[] = "10011";  // Example divisor in binary

    int dataLength = strlen(data);
    int divisorLength = strlen(divisor);

    // Calculate CRC
    calculateCRC(data, dataLength, divisor, divisorLength);

    // Print the final CRC
    printf("CRC Result: %s\n", data);

    return 0;
}
