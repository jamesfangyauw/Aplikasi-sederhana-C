#include <stdio.h>
#include <string.h>
#include "pilihmatkul.c"
int nilai[9][15]; //variabel buat nyimpen nilai tiap matkul
                  //dalam 7 semester
int copy[9][15];
void input(){
    FILE *fp;
    strcpy(session, akun.uname);
    char format[5] = ".csv", buff_1[2];
    strcat(session, format);
    pilih_matkul();

    fp = fopen(session, "a+");

    printf(" Inputkan nilai Anda pada tiap mata kuliah yang Anda ambil\n");
    switch (semesterbrp){
        case 1:
            for (int i = 0; i < banyak; i++){
                printf(" %s = ", matkul_1[pil_matkul[i]-1]);
                scanf("%d", &nilai[0][i]);
                fprintf(fp, "%s,%d\n", matkul_1[pil_matkul[i]-1], nilai[0][i]);
            }
            break;
        case 2:
            for (int i = 0; i < banyak; i++){
                printf(" %s = ", matkul_2[pil_matkul[i]-1]);
                scanf("%d", &nilai[1][i]);
                fprintf(fp, "%s,%d\n", matkul_2[pil_matkul[i]-1], nilai[1][i]);
            }
            break;
        case 3:
            for (int i = 0; i < banyak; i++){
                printf(" %s = ", matkul_3[pil_matkul[i]-1]);
                scanf("%d", &nilai[2][i]);
                fprintf(fp, "%s,%d\n", matkul_3[pil_matkul[i]-1], nilai[2][i]);
            }
            break;
        case 4:
            for (int i = 0; i < banyak; i++){
                printf(" %s = ", matkul_4[pil_matkul[i]-1]);
                scanf("%d", &nilai[3][i]);
                fprintf(fp, "%s,%d\n", matkul_4[pil_matkul[i]-1], nilai[3][i]);
            }
            break;
        case 5:
            for (int i = 0; i < banyak; i++){
                printf(" %s = ", matkul_5[pil_matkul[i]-1]);
                scanf("%d", &nilai[4][i]);
                fprintf(fp, "%s,%d\n", matkul_5[pil_matkul[i]-1], nilai[4][i]);
            }
            break;
        case 6:
            for (int i = 0; i < banyak; i++){
                printf(" %s = ", matkul_6[pil_matkul[i]-1]);
                scanf("%d", &nilai[5][i]);
                fprintf(fp, "%s,%d\n", matkul_6[pil_matkul[i]-1], nilai[5][i]);
            }
            break;
        case 7:
            for (int i = 0; i < banyak; i++){
                printf(" %s = ", matkul_7[pil_matkul[i]-1]);
                scanf("%d", &nilai[6][i]);
                fprintf(fp, "%s,%d\n", matkul_7[pil_matkul[i]-1], nilai[6][i]);
            }
            break;
        case 8:
            for (int i = 0; i < banyak; i++){
                printf(" %s = ", matkul_8[pil_matkul[i]-1]);
                scanf("%d", &nilai[7][i]);
                fprintf(fp, "%s,%d\n", matkul_8[pil_matkul[i]-1], nilai[7][i]);
            }
            break;
        default:
            break;
    }

    fclose(fp);
}
