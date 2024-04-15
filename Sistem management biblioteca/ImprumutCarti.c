#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprumutare_carti()
{

    int ok = 0,i=0, nr_exemplare;
    char titlu[100], autor[100],nume[100],prenume[100];


    printf("\033[38;5;225m");//mov mai deschis
    printf("Introduceti numele dvs: ");
    scanf("%s", nume);
    printf("\n");
    printf("Introduceti prenumele dvs: ");
    scanf("%s", prenume);
    printf("\n");


    // Verificăm utilizatorul este în fișierul CSV
    if (verificare_utilizator(nume, prenume)==0)
        {
            printf("Utilizatorul nu exista");
            return;
        }
    printf("Introduceti Titlul cartii pe care doriti sa o imprumutati: ");
    scanf(" %[^\n]%*c", titlu); //citim titlul ignorand spatiile albe, pana la intalnirea caracterului newline
    printf("\n");
    printf("Introduceti Autorul cartii pe care doriti sa o imprumutati: ");
    scanf(" %[^\n]%*c", autor); //citim autorul ignorand spatiile albe, pana la intalnirea caracterului newline
    printf("\n");
    printf("Introduceti numarul de exemplare:");
    if (scanf("%d", &nr_exemplare) != 1 || nr_exemplare <= 0) {
                printf("\n");
        printf("Numarul de exemplare introdus nu este valid.\n");
        return;
    }
    printf("\n");


    FILE *fisier = fopen("data.csv", "r");
    if (fisier == NULL) {
        printf("Eroare la deschiderea fisierului.\n");
        return;
    }

    FILE *fisier_temp = fopen("temp.csv", "w");
    if (fisier_temp == NULL) {
        printf("Eroare la crearea fisierului temporar.\n");
        fclose(fisier);
        return;
    }

    char linie[1000];
    //parcurgem fiecare linie din fisier
    while (fgets(linie, sizeof(linie), fisier)) {
        //extragem titlul si autorul din linia la care suntem, folosindu-ne de separatorul ","
        char *titlu_curent = strtok(linie, ",");
        char *autor_curent = strtok(NULL, ",");
        char *exemplare_str = strtok(NULL, ",");

        //verificam daca titlul si autorul sunt aceleasi cu cele citite
        if (strcmp(titlu_curent, titlu) == 0 && strcmp(autor_curent, autor) == 0) {
            int exemplare = atoi(exemplare_str); // convertim numărul de exemplare la întreg
            ok = 1;
            if (nr_exemplare <= exemplare) {
                exemplare -= nr_exemplare;



    // Deschidem fișierul "Imprumuturi.txt" în modul de adăugare (append)
    FILE *fisier_imprumuturi = fopen("Imprumuturi.txt", "a");
    if (fisier_imprumuturi == NULL) {
        printf("Eroare la deschiderea fisierului 'Imprumuturi'.\n");
        return;
    }

    // Adăugăm detaliile despre imprumut în fișier
    fprintf(fisier_imprumuturi, "%s %s,%s,%s,%d\n", nume, prenume, titlu, autor, nr_exemplare);

    // Închidem fișierul "Imprumuturi.txt"
    fclose(fisier_imprumuturi);
    //seteaza culoarea textului la verde
    printf("\033[38;5;40m");
    printf("Imprumutul a fost inregistrat cu succes.\n\n\n");
    //cream fisa de imprumut
    printf("\033[38;5;225m"); // mov mai deschis
    printf("-------FISA DE IMPRUMUT-------\n\n");
    printf("Nume: %s\n",nume);
    printf("Prenume: %s\n",prenume);
    printf("Titlul si autorul cartii imprumutate: %s - %s\n",titlu,autor);
    printf("Numarul cartilor imprumutate: %d\n\n",nr_exemplare);
    printf("-------------------------------\n\n");




            } else {
                printf("Nu exista suficiente exemplare disponibile pentru imprumut.\n");
                fclose(fisier);
                fclose(fisier_temp);
                remove("temp.csv");
                return;
            }
            fprintf(fisier_temp, "%s,%s,%d\n", titlu_curent, autor_curent, exemplare);
        } else {
            fprintf(fisier_temp, "%s,%s,%s", titlu_curent, autor_curent, exemplare_str);
        }
    }

    if (ok == 0) {
        printf("Cartea nu a fost gasita.\n");
    }

    fclose(fisier);
    fclose(fisier_temp);

    remove("data.csv");
    rename("temp.csv", "data.csv");

}
void vizualizare_imprumuturi(const char nume[], const char prenume[]) {
    int ok=1;

    FILE *file = fopen("Imprumuturi.txt", "r");
    if (file == NULL) {
        printf("Eroare la deschiderea fisierului 'Imprumuturi'.\n");
        return;
    }
    printf("\n");

    printf("Ati efectuat urmatoarele imprumuturi:\n\n");
    char nume_complet[200];
    sprintf(nume_complet, "%s %s", nume, prenume);

    char linie[1000];
    while (fgets(linie, sizeof(linie), file)) {
        char *token = strtok(linie, ",");
        if (strcmp(nume_complet, token) == 0) {

            token = strtok(NULL, ",");
            printf("Titlu: %s, ", token);

            token = strtok(NULL, ",");
            printf("Autor: %s, ", token);

            token = strtok(NULL, ",");
            printf("Exemplare: %s\n", token);
            ok=0;
        }
    }
     if(ok==1)
     {
      printf("Nu ati efectuat niciun imprumut.\n");
     }
    fclose(file);
}
