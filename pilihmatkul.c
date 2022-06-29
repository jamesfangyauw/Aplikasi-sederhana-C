#include <stdio.h>
#include "matkul.c"

void swap();
void sort();
void semester();

int pil_matkul[10];
int banyakmatkul;
int semesterbrp;
int banyak;

int pilih_matkul(){
    char buff[30];
    printf("Semester : ");
    scanf("%d", &semesterbrp);
    printf("\n");
    semester(semesterbrp);
    printf("\nBanyak Mata Kuliah yang akan diambil : ");
    scanf("%d", &banyak);
    printf("Mata Kuliah yang diambil : ");
    for(int i=0; i<banyak; i++){
        scanf("\n%d", &pil_matkul[i]);
    }
    sort(pil_matkul, banyak);
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int jmlh) {
    for(int i = 0; i < jmlh; i++) {
        for(int j = 0; j < jmlh; j++) {
            if(arr[j] > arr[i]) {
                swap(&arr[j], &arr[i]);
            }
        }
    }
}

void semester(int n){
    switch (n){
    case  1 :
        printf("          SEMESTER 1         \n");
        printf("+=============================+\n");
        printf("|  1. Bahasa Ingris           |\n");
        printf("|  2. Matematika Informatika  |\n");
        printf("|  3. Sistem Digital          |\n");
        printf("|  4. Kewarganegaraan         |\n");
        printf("|  5. Bahasa Indonesia        |\n");
        printf("|  6. Matematika Diskrit I    |\n");
        printf("|  7. Algoritma & Pemrograman |\n");
        printf("|  8. Statistika Dasar        |\n");
        printf("+=============================+\n");
        banyakmatkul = 8;
        break;
    case  2 :
        printf("          SEMESTER 2         \n");
        printf("+===============================+\n");
        printf("|  1. Ilmu Sosial Budaya Dasar  |\n");
        printf("|  2. Pendidikan Agama          |\n");
        printf("|  3. Matematika Diskrit II     |\n");
        printf("|  4. Struktur Data             |\n");
        printf("|  5. Sistem Operasi            |\n");
        printf("|  6. Pengantar Probabilitas    |\n");
        printf("|  7. Organisasi dan Arsitektur |\n|     Komputer                  |\n");
        printf("|  8. Praktikum Sistem Digital  |\n");
        printf("|  9. Praktikum Algoritma dan   |\n|     Pemrograman               |\n");
        printf("+===============================+\n");
        banyakmatkul = 9;
        break;
    case  3 :
        printf("          SEMESTER 3         \n");
        printf("+===================================+\n");
        printf("| 1. Interaksi Manusia dan Komputer |\n");
        printf("| 2. Basis Data                     |\n");
        printf("| 3. Desain dan Analisis Algoritma  |\n");
        printf("| 4. Rekayasa Perangkat Lunak       |\n");
        printf("| 5. Pemrograman Berorientasi Obyek |\n");
        printf("| 6. Komunikasi Data dan Jaringan   |\n|    Komputer                       |\n");
        printf("| 7. Praktikum Sistem Operasi       |\n");
        printf("| 8. Praktikum Struktur Data        |\n");
        printf("| 9. Interaksi Manusia dan Komputer |\n");
        printf("+===================================+\n");
        banyakmatkul = 9;
        break;
    case  4 :
        printf("               SEMESTER 4                   \n");
        printf("+==========================================+\n");
        printf("|  1. Praktikum Basis Bata                 |\n");
        printf("|  2. Metode Penelitian                    |\n");
        printf("|  3. Kewirausahaan                        |\n");
        printf("|  4. Pengantar Kecerdasan Buatan          |\n");
        printf("|  5. Analisis dan Desain Sistem           |\n");
        printf("|  6. Sistem Informasi                     |\n");
        printf("|  7. Pengantar Pemrosesan Data Multimedia |\n");
        printf("|  8. Keamanan Jaringan                    |\n");
        printf("+==========================================+\n");
        banyakmatkul = 8;
        break;
    case  5 :
        printf("+==========================================+\n");
        printf("|  1. Praktikum Data dan Jaringan Komputer |\n");
        printf("|  2. Teori Bahasa dan Otomata             |\n");
        printf("|  3. Sistem Informasi                     |\n");
        printf("|  4. Pemodelan dan Simulasi               |\n");
        printf("|  5. Grafika Komputer                     |\n");
        printf("+==========================================+\n");
        break;
    case  6 :
        printf("+==============================================+\n");
        printf("|  1. Tata Tulis Karya Ilmiah                  |\n");
        printf("|  2. Penambangan Data Tekstual                |\n");
        printf("|  3. Temu Kembali Informasi Tekstual          |\n");
        printf("|  4. Pembelajaran Mesin Untuk Data Tekstual   |\n");
        printf("|  5. Pemrosesan Bhasa Alami                   |\n");
        printf("|  6. Manajemen Pengetahuan Semantik           |\n");
        printf("|  7. Sistem Manajemen Pengetahuan             |\n");
        printf("|  8. Warisan Budaya Digital                   |\n");
        printf("|  9. Intelijen Bisnis dan Analisis            |\n");
        printf("| 10. Pemrosesan Sinyal Digital                |\n");
        printf("| 11. Pengenalan Pola                          |\n");
        printf("| 12. Sistem Temu Kembali Informasi Musik      |\n");
        printf("| 13. Sintesis Bunyi                           |\n");
        printf("| 14. Pengolahan Bunyi Digital                 |\n");
        printf("| 15. Pengolahan Citra Digital                 |\n");
        printf("| 16. Kompresi Data Multimedia                 |\n");
        printf("| 17. Sistem Multimedia                        |\n");
        printf("| 18. Kriptografi                              |\n");
        printf("| 19. Kriptoanalisis                           |\n");
        printf("| 20. Keamanan Sistem Informasi                |\n");
        printf("| 21. Forensik Digital                         |\n");
        printf("| 22. Teknologi Nirkabel                       |\n");
        printf("| 23. Jaringan Sensor Terdistribusi            |\n");
        printf("| 24. Integrasi Data dan Sensor                |\n");
        printf("| 24. Pemrosesan Dalam Jaringan                |\n");
        printf("| 25. Analisis dan Pengolahan Data Digital     |\n");
        printf("| 26. Metode Kecerdasan Buatan Lanjut          |\n");
        printf("| 27. Metode Penalaran                         |\n");
        printf("| 28. Sistem Pakar                             |\n");
        printf("| 29. Manajemen Proyek Teknologi Informasi     |\n");
        printf("| 30. Penambangan Data dan Analisis            |\n");
        printf("| 31. Pemrograman Berbasis Mobile              |\n");
        printf("| 32. Gudang Data dan Basis Data Terdistribusi |\n");
        printf("| 33. Perancangan Interaksi                    |\n");
        printf("| 34. Realitas Campuran, Tertambah dan Virtual |\n");
        printf("| 35. Pemrograman Sistem Interaktif            |\n");
        printf("| 36. Metode Statistika untuk Interaksi        |\n|     Manusia Komputer                         |\n");
        printf("+==============================================+\n");
        break;
    case  7 :
        printf("+==========================================+\n");
        printf("|  1. Desain dan Pengujian Berpusat Pada   |\n|     Pengguna                             |\n");
        printf("|  2. Pemrosesan Data Tekstual pada Web    |\n");
        printf("|  3. Manajemen Data dan Informasi         |\n");
        printf("|  4. Pengantar Pembelajaran Mesin         |\n");
        printf("|  5. Jaringan Multimedia                  |\n");
        printf("|  6. Keamanan Sistem Mobile               |\n");
        printf("|  7. Pemrograman Ubikuitas                |\n");
        printf("|  8. Sistem Optimasi                      |\n");
        printf("|  9. Perdagangan Elektronik dan Intelijen |\n|     Bisnis                               |\n");
        printf("| 10. Ergonomi Terapan                     |\n");
        printf("+==========================================+\n");
        break;
    case 8  :
        printf("+====================================+\n");
        printf("|  1. Tugas Akhir                    |\n");
        printf("+====================================+\n");
        break;
    }
}
