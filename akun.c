#include <stdio.h>
#include <stdlib.h>

char session[100];

struct akun_login{
    char uname[100];
    char pass[100];
};

struct akun_login akun;
struct akun_login edit;

int hitung_baris(char file[]){
    FILE *fp;
    fp = fopen(file, "r");
    int baris = 0;
    char buff;
    while (!feof(fp)){
        buff = fgetc(fp);
        if (buff == '\n'){
            baris++;
        }
    }
    fclose (fp);
    return baris;
}

void akun_default(){
    FILE *fp;
    int uname = 2008561001;
    int pass = 2008561001;
    fp = fopen("data_login.csv", "w");
    fprintf(fp, "%d,%d\n", 1908561100, 1908561100);
    fprintf(fp, "%d,%d\n", 1908561091, 1908561091);
    for (int i = 0; i < 111; i++){
        fprintf(fp, "%d,%d\n", uname, pass);
        uname++;
        pass++;
    }
    fclose(fp);
}
int login(){
    FILE *fp;

    char file[] = "data_login.csv";
    char uname[100], pass[100];
    int baris = hitung_baris(file);
    int cek = 0;

    fp = fopen(file, "r");

    printf(" USERNAME: ");
    scanf("\n");
    scanf("%[^\n]%*c", uname);
    printf(" PASSWORD: ");
    scanf("\n");
    scanf("%[^\n]%*c", pass);

    for (int i = 0; i < baris && cek == 0; i++){
        fscanf(fp, "\n%[^,],%[^\n]", akun.uname, akun.pass);

        int cek_uname = strcmp(akun.uname, uname);
        int cek_pass = strcmp(akun.pass, pass);

        if (cek_uname == 0 && cek_pass == 0){
            cek = 1;
            strcpy(session, akun.uname);
        }else {
            cek = 0;
        }
    }
    fclose(fp);
    return cek;
}
void ganti_pass(){
    FILE *fptr, *fpsementara;
    char pass_baru[40];
    char file[] = "data_login.csv";
    int baris = hitung_baris(file);

    printf(" Ketikkan password yang baru: ");
    scanf("\n");
    scanf("%[^\n]*c", pass_baru);

    fptr = fopen(file, "r");
    fpsementara = fopen("sementara.csv", "w");

    for (int i = 0; i < baris; i++){
        fscanf(fptr, "\n%[^,],%[^\n]", edit.uname, edit.pass);
        if (strcmp(edit.uname, akun.uname) == 0){
            fprintf(fpsementara, "%s,%s\n", edit.uname, pass_baru);
        }else {
            fprintf(fpsementara, "%s,%s\n", edit.uname, edit.pass);
        }
    }
    fclose (fptr);
    fclose (fpsementara);
    remove(file);
    int cek = rename ("sementara.csv", file);
    if (cek == 0){
        printf(" Berhasil di-edit\n");
    }
}
void hapus(){
    FILE *fp;
    int cek;
    strcpy(session, akun.uname);
    char format[5] = ".csv", buff_1[2];
    strcat(session, format);

    fp = fopen(session, "r");

    //ini buat ngecek apakah filenya
    //dah ada atau belum
    if (fp == NULL){
        printf(" File %s tidak ada\n", session);
    }else {
        fclose (fp);
        cek = remove(session);
        if (cek == 0){
            printf( "File %s berhasil dihapus\n", session);
        }else {
            printf( "File %s gagal dihapus\n", session);
        }
    }
    fclose (fp);
}
