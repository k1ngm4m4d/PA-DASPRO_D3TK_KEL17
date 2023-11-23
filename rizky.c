#include <stdio.h>

void biner_ke_polinomial(const char *binary) {
    // Example implementation: print the binary representation and its length.
    printf("Binary: %s\n", binary);
    printf("Length: %lu\n", strlen(binary));
}

int main() {
    FILE *file = fopen("data_nim.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return -1;
    }

    int NIM[20];
    int i = 0;

    while (fscanf(file, "%d", &NIM[i]) == 1 && i < 20) {
        i++;
    }

    fclose(file);

    if (i < 20) {
        printf("Gagal membaca NIM dari file.\n");
        return -1;
    }

    for (int j = 0; j < i; j++) {
        char bilangan_biner[33]; // 32 bits + null terminator
        snprintf(bilangan_biner, sizeof(bilangan_biner), "%d", NIM[j]);
        printf("NIM_%d_Biner: %s\n", j + 1, bilangan_biner);
        printf("NIM_%d_Polinomial: ", j + 1);
        biner_ke_polinomial(bilangan_biner);
    }

    return 0;
}
