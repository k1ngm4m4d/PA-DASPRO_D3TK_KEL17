#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform CRC calculation
void calculateCRC(char *data, int dataLength, char *divisor, int divisorLength)
{
    // Append zeros to data based on divisor length
    for (int i = 0; i < divisorLength - 1; i++)
    {
        strcat(data, "0");
    }

    int dataSize = strlen(data);

    // Perform CRC calculation
    for (int i = 0; i < dataSize - divisorLength + 1; i++)
    {
        if (data[i] == '1')
        {
            // XOR operation
            for (int j = 0; j < divisorLength; j++)
            {
                data[i + j] = (data[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }
}

// Function to convert polynomial to binary
void polynomialToBinary(char *polynomial, int degree, char *binary)
{
    // Convert the polynomial to binary representation
    for (int i = degree; i >= 0; i--)
    {
        if (polynomial[i] == '1')
        {
            strcat(binary, "1");
            if (i > 0)
                strcat(binary, " + ");
            else
                strcat(binary, " ");
        }
        else if (polynomial[i] == '0')
        {
            if (i > 0)
                strcat(binary, "0 + ");
            else
                strcat(binary, "0 ");
        }
    }
}

int main()
{
    FILE *file = fopen("data_nim.txt", "r");
    if (file == NULL)
    {
        printf("Gagal membuka file.\n");
        return -1;
    }

    int NIM[20];
    int i = 0;

    while (fscanf(file, "%d", &NIM[i]) != EOF && i < 20)
    {
        i++;
    }

    fclose(file);

    if (i < 20)
    {
        printf("Gagal membaca NIM dari file.\n");
        return -1;
    }

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Gagal membuat file output.\n");
        return -1;
    }

    // Using NIM for operations
    for (int j = 0; j < i; j++)
    {
        char binaryNIM[32]; // maximum binary length needed
        itoa(NIM[j], binaryNIM, 2);

        fprintf(outputFile, "NIM_%d: %d\n", j + 1, NIM[j]);
        fprintf(outputFile, "NIM_%d_Biner: %s\n", j + 1, binaryNIM);

        // Determine divisor polynomial based on the length of binaryNIM
        int divisorDegree = strlen(binaryNIM) - 1;
        char divisor[divisorDegree + 2]; // +1 for null terminator, +1 for leading '1'
        strcpy(divisor, "1");
        for (int k = 0; k < divisorDegree; k++)
        {
            strcat(divisor, "0");
        }

        fprintf(outputFile, "Divisor_Polynomial: ");
        char divisorBinary[32] = "";
        polynomialToBinary(divisor, divisorDegree, divisorBinary);
        fprintf(outputFile, "%s\n", divisorBinary);
        fprintf(outputFile, "Primitive_Polynomial: %s\n", divisor);
        fprintf(outputFile, "Primitive_Polynomial_Biner: %s\n", divisorBinary);

        // Calculate CRC
        calculateCRC(binaryNIM, strlen(binaryNIM), divisor, divisorDegree + 1);

        fprintf(outputFile, "CRC_Result: %s\n", binaryNIM);
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);

    return 0;
}
