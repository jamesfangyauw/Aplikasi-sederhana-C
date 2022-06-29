/*
    ANGGOTA:
    1. KADEK DIAH PRAMESTI               2008561068
    2. KADEK YOGA VIDYA PRADNYADITHA     2008561069
    3. I NENGAH OKA DARMAYASA            2008561070
    4. NI PUTU ANGELINA PATRISIA PUTRI   2008561075
    5. YAUW JAMES FANG DWIPUTRA HARTA    2008561078

    * INI MERUPAKAN PROGRAM YANG KAMI BERIKAN JUDUL
                PROGRAM MINI-SIMAK

      **INTI PROGRAM INI ADALAH MENYIMPAN DATA NILAI
      TIAP MAHASISWA SELAMA MEREKA BELAJAR DI
      UNIVERSITAS UDAYANA SELAMA BERAPA SEMESTER
      MEREKA AMBIL DI UDAYANA.
      **NILAI YANG DISIMPAN ADALAH NILAI YANG
      DI-INPUT MANUAL OLEH USER.
      **NILAI INI NANTINYA AKAN DISIMPAN KE DALAM
      FILE YANG BERBEDA UNTUK SETIAP MAHASISWANYA
      (JADI AKAN ADA FILE SEBANYAK JUMLAH MAHASISWA)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "akun.c"
#include "landing.c"
#include "input.c"
#include "tampil.c"

struct akun_login akun;

void menu();

int main(){
    FILE *fpr;
    fpr = fopen("data_login.csv", "r");

    //ini buat ngecek apakah file data username
    //dan passwordnya dah ada atau belum
    if (fpr == NULL){
        akun_default();
    }
    fclose (fpr);

    //di sini memanggil fungsi untuk menampilkan
    //header
    landing();

    //di sini dilakukan pemanggilan fungsi login
    //yang gunanya untuk login
    // *fungsi login ada di dalam file akun.c
    if (login() == 1){
        printf(" Berhasil Login!\n");
        menu();
    }else {
        printf(" Username atau Password Anda salah!\n");
        getch();
        system("cls");
        main();
    }
    return 0;
}

void menu(){
    int pilih;

    printf(" 1. INPUT NILAI\n");
    printf(" 2. TAMPIL NILAI\n");
    printf(" 3. GANTI PASSWORD\n");
    printf(" 4. HAPUS \n");
    printf(" 5. EXIT\n");
    printf(" Pilihan: ");
    scanf("%d", &pilih);

    switch (pilih){
        case 1:
            input();
            getch();
            system("cls");
            landing();
            menu();
            break;
        case 2:
            tampil();
            getch();
            system("cls");
            landing();
            menu();
            break;
        case 3:
            ganti_pass();
            getch();
            system("cls");
            landing();
            menu();
            break;
        case 4:
            hapus();
            getch();
            system("cls");
            landing();
            menu();
            break;
        case 5:
            system("cls");
            printf("============================================================================================\n");
            printf("|  _______ ______ _____  _____ __  __            _  __           _____ _____ _    _        |\n");
            printf("| |__   __|  ____|  __ \\|_   _|  \\/  |   /\\     | |/ /    /\\    / ____|_   _| |  | |       |\n");
            printf("|    | |  | |__  | |__) | | | | \\  / |  /  \\    | ' /    /  \\  | (___   | | | |__| |       |\n");
            printf("|    | |  |  __| |  _  /  | | | |\\/| | / /\\ \\   |  <    / /\\ \\  \\___ \\  | | |  __  |       |\n");
            printf("|    | |  | |____| | \\ \\ _| |_| |  | |/ ____ \\  | . \\  / ____ \\ ____) |_| |_| |  | |       |\n");
            printf("|    |_|  |______|_|  \\_\\_____|_|  |_/_/    \\_\\ |_|\\_\\/_/    \\_\\_____/|_____|_|  |_|       |\n");
            printf("============================================================================================\n");
            break;
        default:
            landing();
            menu();
            break;
    }
}

