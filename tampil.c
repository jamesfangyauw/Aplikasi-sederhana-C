#include <stdio.h>

void tampil(){
    FILE *fp;
    strcpy(session, akun.uname);
    char format[5] = ".csv", buff_1[2];
    strcat(session, format);

    int nilai;
    char matkul[80];
    fp = fopen(session, "r");
    if (fp == NULL){
        printf(" File %s tidak ada\n", session);
    }else {
        int baris = hitung_baris(session);
        printf("+==============================+====+\n");
        for (int i = 0; i < baris; i++){
            fscanf(fp, "\n%[^,],%d", matkul, &nilai);
            printf("| %-29s%| %-3d|\n", matkul, nilai);
        }
        printf("+==============================+====+\n");
    }
    fclose (fp);
}
