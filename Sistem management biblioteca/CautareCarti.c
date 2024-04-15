#include <stdio.h>
#include <string.h>

//functie pt cautarea dupa titlu sau autor
void cautare_carti1() {
    int ok=0;//setam variabila ok la 0 pt a verifica daca cartea a fost gasita sau nu in fisier
    char subsir[100];
       printf("\033[38;5;225m");//mov mai deschis
    printf("Introduceti Titlul/Autorul cautat:");
    scanf("%s", subsir);
    printf("\n");

    FILE *fisier = fopen("data.csv", "r"); //deschidem fișierul CSV in modul read
    if (fisier == NULL)
    {
        printf("Eroare la deschiderea fisierului.\n");
        return;
    }

    char linie[1000]; // pentru a citi liniile din fișier
    int nr_linii = 0; // variabila pt a stoca nr de linii

    //parcurgem fiecare linie din fisier
    while (fgets(linie, sizeof(linie), fisier))
    {
        nr_linii++;

        //cautam subsirul citit de la tastatura in linia la care suntem in fisierul csv
        if (strstr(linie, subsir) != NULL)
        { //daca subsirul este gasit
            char *titlu = strtok(linie, ",");
            char *autor = strtok(NULL, ",");
            char *exemplare = strtok(NULL, ",");
            printf("Cartea '%s' scrisa de %s are %s exemplare in stoc.\n\n", titlu, autor, exemplare, nr_linii);
            ok=1;//daca cartea a fost gasita, ok devine 1
        }
    }

    if(ok==0) printf("Cartea nu a fost gasita");//daca ok ramane 0, cartea nu a fost gasita
   printf("\033[38;5;207m");//Setarea culorii textului la mov

    fclose(fisier);
}

//functie pentru cautarea dupa titlu+autor
void cautare_carti2() {
    int ok = 0;
    char titlu[100], autor[100];
    printf("Introduceti Titlul cautat: ");
    scanf(" %[^\n]%*c", titlu); //citim titlul ignorand spatiile albe, pana la intalnirea caracterului newline
    printf("\n");
    printf("Introduceti Autorul cautat: ");
    scanf(" %[^\n]%*c", autor); //citim autorul ignorand spatiile albe, pana la intalnirea caracterului newline
    printf("\n");

    FILE *fisier = fopen("data.csv", "r");
    if (fisier == NULL)
    {
        printf("Eroare la deschiderea fisierului.\n");
        return;
    }

    char linie[1000];
    int nr_linii = 0;

    //parcurgem fiecare linie din fisier
    while (fgets(linie, sizeof(linie), fisier))
    {
        nr_linii++;

        //extragem titlul si autorul din linia la care suntem, folosindu-ne de separatorul ","
        char *titlu_curent = strtok(linie, ",");
        char *autor_curent = strtok(NULL, ",");

        //verificam daca titlul si autorul sunt aceleasi cu cele citite
        if (strcmp(titlu_curent, titlu) == 0 && strcmp(autor_curent, autor) == 0)
        {
            char *exemplare = strtok(NULL, ",");
            printf("Cartea '%s' scrisa de %s are %s exemplare in stoc.\n", titlu_curent, autor_curent, exemplare, nr_linii);
            ok = 1;
            break;
        }
    }

    if (ok==0)
    {
        printf("Cartea nu a fost gasita.\n");
    }

    fclose(fisier);
}
