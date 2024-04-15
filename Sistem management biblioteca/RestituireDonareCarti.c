#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void restituire_carti() {
    char titlu[100], autor[100], nume[100], prenume[100];
    int exemplare_restituite,ok=0;
        printf("\033[38;5;225m");//mov mai deschis
    // Citim detaliile despre cartea care va fi returnată
    printf("Introduceti numele si prenumele dvs: ");
    scanf(" %[^\n]", nume);
    printf("\n");

    printf("Introduceti Titlul cartii pe care doriti sa o returnati: ");
    scanf(" %[^\n]%*c", titlu);
    printf("\n");
    printf("Introduceti Autorul cartii pe care doriti sa o returnati: ");
    scanf(" %[^\n]%*c", autor);
    printf("\n");
    printf("Introduceti numarul de exemplare ale cartii pe care doriti sa o restituiti:");
    if (scanf("%d", &exemplare_restituite) != 1 || exemplare_restituite <= 0) {
        printf("Numarul de exemplare introdus nu este valid.\n");
        return;
    }
    printf("\n");

    FILE *fisier2 = fopen("Imprumuturi.txt", "r+");
    if (fisier2 == NULL) {
        printf("Eroare la deschiderea fisierului Imprumuturi.txt.\n");
        return;
    }

    FILE *fisier_temp = fopen("temp_imprumuturi.txt", "w");
    if (fisier_temp == NULL) {
        printf("Eroare la crearea fisierului temporar temp_imprumuturi.txt.\n");
        fclose(fisier2);
        return;
    }

    char linie[1000];
    //actualizam fisierul Imprumuturi.txt
    while (fgets(linie, sizeof(linie), fisier2)) {
        //extragem numele si prenumele din linia la care suntem, folosindu-ne de separatorul ","
        char *nume_linie = strtok(linie, ",");
        char *titlu_linie = strtok(NULL, ",");
        char *autor_linie = strtok(NULL, ",");
        char *exemplare_str = strtok(NULL, ",");
        int exemplare = (exemplare_str != NULL) ? atoi(exemplare_str) : 0;

        // Verificăm dacă trebuie să eliminăm această linie
        if (strcmp(nume_linie, nume) == 0 && strcmp(titlu_linie, titlu) == 0 && strcmp(autor_linie, autor) == 0) {
            // Actualizăm numărul de exemplare
            exemplare -= exemplare_restituite;

            // Verificăm dacă exemplarele rămase sunt mai mici sau egale cu 0
            if (exemplare <= 0) {
                printf("Toate exemplarele cartii '%s' de '%s' au fost restituite.\n", titlu, autor);
                continue; // Nu mai scriem această linie în fișierul temporar
            }
        }

        // Scriem linia în fișierul temporar
        fprintf(fisier_temp, "%s,%s,%s,%d\n", nume_linie, titlu_linie, autor_linie, exemplare);
    }

    fclose(fisier2);
    fclose(fisier_temp);

    // Redeschidem fisierul "Imprumuturi.txt" pentru rescrierea sa cu continutul din fisierul temporar
    fisier2 = fopen("Imprumuturi.txt", "w");
    if (fisier2 == NULL) {
        printf("Eroare la redeschiderea fisierului Imprumuturi.txt.\n");
        return;
    }

    fisier_temp = fopen("temp_imprumuturi.txt", "r");
    if (fisier_temp == NULL) {
        printf("Eroare la deschiderea fisierului temporar temp_imprumuturi.txt.\n");
        fclose(fisier2);
        return;
    }

    while (fgets(linie, sizeof(linie), fisier_temp)) {
        fprintf(fisier2, "%s", linie);
    }

    fclose(fisier2);
    fclose(fisier_temp);

    remove("temp_imprumuturi.txt");



    FILE *fisier1 = fopen("data.csv", "r");
    if (fisier1 == NULL) {
        printf("Eroare la deschiderea fisierului.\n");
        return;
    }

    FILE *fisier_temp1 = fopen("temp.csv", "w");
    if (fisier_temp1 == NULL) {
        printf("Eroare la crearea fisierului temporar.\n");
        fclose(fisier1);
        return;
    }

   char Linie[1000];
    //actualizam fisierul data.csv
    while (fgets(Linie, sizeof(Linie), fisier1)) {
        //extragem titlul si autorul din linia la care suntem, folosindu-ne de separatorul ","
        char *titlu_curent = strtok(Linie, ",");
        char *autor_curent = strtok(NULL, ",");
        char *exemplare_str = strtok(NULL, ",");

        //verificam daca titlul si autorul sunt aceleasi cu cele citite
        if (strcmp(titlu_curent, titlu) == 0 && strcmp(autor_curent, autor) == 0) {
            int exemplare = atoi(exemplare_str); // convertim numărul de exemplare la întreg
            ok = 1;
            if (exemplare_restituite <=exemplare) {
                exemplare += exemplare_restituite;
            }
            else {
                printf("Nu exista suficiente exemplare disponibile pentru restituire.\n");
                fclose(fisier1);
                fclose(fisier_temp1);
                remove("temp.csv");
                return;
            }
            fprintf(fisier_temp1, "%s,%s,%d\n", titlu_curent, autor_curent, exemplare);
        } else {
            fprintf(fisier_temp1, "%s,%s,%s", titlu_curent, autor_curent, exemplare_str);
        }
    }

    if (ok == 0) {
        printf("Cartea nu a fost gasita.\n");
    }

    fclose(fisier1);
    fclose(fisier_temp1);

    remove("data.csv");
    rename("temp.csv", "data.csv");

    //seteaza culoarea textului la verde
    printf("\033[38;5;40m");
    printf("Restituirea s-a efectuat cu succes!");
}
void donare_carti()
{
    char titlu[100], autor[100];
    int exemplare;
    printf("Introduceti titlul cartii pe care doriti sa o donati:");
    scanf(" %[^\n]", titlu); // Citirea întregului șir până la newline
    printf("\n\n");
    printf("Introduceti autorul cartii pe care doriti sa o donati:");
    scanf(" %[^\n]", autor);
    printf("\n\n");
    printf("Introduceti numarul de exemplare pe care doriti sa il donati:");
    scanf("%d", &exemplare);
    printf("\n\n");



    FILE *fisier = fopen("data.csv", "a"); // Deschidem fisierul in modul "append"
    if (exemplare <= 0) {
    printf("Numarul de exemplare introdus nu este valid.\n");
    fclose(fisier);
    return;
    }
    if (exemplare <= 0) {
    printf("Numarul de exemplare introdus nu este valid.\n");
    fclose(fisier);
    return;
}

    if (fisier == NULL) {
        printf("Eroare la deschiderea fisierului.\n");
        return;
    }

    fprintf(fisier, "%s,%s,%d\n", titlu, autor, exemplare);
    //seteaza culoarea textului la verde
    printf("\033[38;5;40m");
    printf("Donarea a avut loc cu succes");

    fclose(fisier);
}

