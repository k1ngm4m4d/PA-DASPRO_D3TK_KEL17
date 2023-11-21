#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk mengonversi bilangan biner ke bentuk polinomial
void biner_ke_polinomial(char* biner) {
    int i;
    int panjang = strlen(biner);
    int sudah_ada_suku = 0; // Menandakan apakah sudah ada suku pada polinomial
    for (i = 0; i < panjang; i++) {
        if (biner[i] == '1') {
            if (sudah_ada_suku) {
                printf(" + ");
            }
            printf("x^%d", panjang - i - 1);
            sudah_ada_suku = 1;
        }
    }
    if (!sudah_ada_suku) {
        printf("0"); // Jika tidak ada suku (semua bit 0)
    }
    printf("\n");
}

int main() {

    // membaca NIM dari file
    FILE *file = fopen("data_nim.txt", "r"); 
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return -1;
    }

    int NIM[20];
    int i = 0;
    while (fscanf(file, "%d", &NIM[i]) != EOF && i < 20) {
        i++;
    }

    fclose(file);

    // mencek apakah berhasil membaca 20 NIM
    if (i < 20) {
        printf("Gagal membaca NIM dari file.\n");
        return -1;
    }

    //menggunakan NIM yang di simpan tadi  untuk operasi yang diinginkan
    for (int j = 0; j < 20; j++) {
        char bilangan_biner[32]; // panjang maksimum biner yang kami dibutuhkan
        itoa(NIM[j], bilangan_biner, 2);
        printf("NIM_%d_Biner: %s\n", j + 1, bilangan_biner);
        printf("NIM_%d_Polinomial: ", j + 1);
        biner_ke_polinomial(bilangan_biner);
    }

    return 0;
}
