#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"
int main(int argc, char** argv)
{
    char Nume[100], Prenume[100];

    char path[] = "data.csv";
    int optiune,opt;
    // Verificăm dacă numărul de argumente este corect
    if (argc != 3) {
        printf("Utilizare: %s login [Nume] [Prenume]\n", argv[0]);
        return 1; //iesim din program cu cod de eroare
    }

    // Verificăm utilizatorul este în fișierul CSV
    if (verificare_utilizator(argv[1], argv[2])==1) {
       //seteaza culoarea textului la verde
        printf("\033[38;5;40m");
        printf("Logare cu succes! Bine ai venit, %s %s!\n", argv[1], argv[2]);

      //seteaza culoarea textului la roz mai inchis
        printf("\033[38;5;207m");

    printf("\n\n\n\n\n");
    printf("                                     =========================================                                     \n");
    printf("                                   =                                           =                                      \n");
    printf("                                  =                                             =                                      \n");
    printf("                                 =                                               =                                      \n");
    printf("                                 =         BINE ATI VENIT LA BIBLIOTECA!         =                                      \n");
    printf("                                 =                                               =                                      \n");
    printf("                                  =                                             =                                      \n");
    printf("                                   =                                           =                                      \n");
    printf("                                     =========================================                                      \n");

        do{
        antet();
            printf("\n");
        printf("                                                 Introduceti optiunea: ");
        //scanf("%d",&optiune);
        if (scanf("%d", &optiune) != 1 || optiune < 0 || optiune > 4) {
            clear_input_buffer(); // șterge buffer-ul de intrare
            printf("\n\n\n\n\n");
            printf("\033[1;31m"); //setarea textului la culoarea roșie
            printf("Optiune invalida. Introduceti o valoare intre 0 si 4.\n");
            printf("\033[38;5;207m");  //seteaza culoarea textului la roz mai inchis
            continue; // trece la următoarea iterare a buclei
        }

        printf("\n\n\n\n");
        meniu(optiune, path);
       printf("\033[38;5;207m");  //seteaza culoarea textului la roz mai inchis


    } while(optiune>0 && optiune<=4);
    //while(optiune != 0 && (optiune < 1 || optiune > 4));
    //while(optiune !=0 && optiune > 4);


    } else if (verificare_utilizator(argv[1], argv[2])==0) {
       printf("\033[1;31m"); //setarea textului la culoarea roșie
       printf("Utilizatorul %s %s nu a fost gasit.\n\n", argv[1], argv[2]);
       printf("\033[38;5;207m");  //seteaza culoarea textului la roz mai inchis
       printf("Doriti sa va creati un cont?\n\n");
       printf("------------------\n");
       printf("  1.Creare cont\n  2.Iesire\n");
       printf("------------------\n");
       scanf("%d",&opt);
       switch (opt) {
            case 1:
                creare();
                break;
            case 2:
                return 0;
                break;
            default:
                printf("\033[1;31m"); //setarea textului la culoarea roșie
                printf("Optiune invalida.\n");
                break;
       }
       }

    //pentru a testa programul trebuie introdusa comanda: cd Desktop\codeblocks\Sistem management biblioteca\bin\Debug
    // iar apoi comanda "Sistem management biblioteca.exe" nume prenume

    //readFromCSV("data.csv");

    return 0;
}
