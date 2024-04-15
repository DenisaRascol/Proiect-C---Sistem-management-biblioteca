#include <stdio.h>
#include <string.h>


//functie de logare pt logarea de pe linia de comanda
int verificare_utilizator(const char* nume, const char* prenume) {
    char line[255];
    FILE* file = fopen("data2.csv", "r");
    if (file == NULL)
    {
        printf("Eroare la deschiderea fisierului.\n");
        return 0;
    }

    fgets(line, 255, file);//ignoram prima linie

    //citim fiecare linie din fișier
    while (fgets(line, 255, file)) {
        char temp_nume[100], temp_prenume[100];
        sscanf(line, "%[^,],%s", temp_nume, temp_prenume);
        if (strcmp(temp_nume, nume) == 0 && strcmp(temp_prenume, prenume) == 0) //daca utilizatorul a fost gasit
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0; //daca utilizatorul nu a fost gasit;
}

//functia de logare pt logarea dupa crearea contului (daca contul nu a fost gasit initial)
void logare(const char* nume, const char* prenume)
{
    int optiune;
    char path[] = "data.csv";
    if (verificare_utilizator(nume, prenume) == 1)
    {
        printf("Logare cu succes! Bine ai venit, %s %s!\n", nume, prenume);

       printf("\033[38;5;207m");  //seteaza culoarea textului la roz mai inchis
        do{
        antet();
            printf("\n");
        printf("                                                 Introduceti optiunea: ");
        scanf("%d",&optiune);
        printf("\n\n\n\n");
        meniu(optiune, path);
    } while(optiune>0 && optiune<=4);


    } else {
        printf("Utilizatorul %s %s nu a fost gasit.\n", nume, prenume);}
}

//functie pt creearea unui cont daca acesta nu a fost gasit
void creare()
{
    int opt;
     char nume[50], prenume[50];
    printf("\033[38;5;225m");//mov mai deschis
    printf("\n");
    printf("Introduceti numele: ");
    scanf("%s", nume);
    printf("\n");
    printf("Introduceti prenumele: ");
    scanf("%s", prenume);
    printf("\n");

    FILE* file = fopen("data2.csv", "a"); //daca fisierul nu exista, va fi creeat

    if (file == NULL)
    {
        printf("Eroare la deschiderea fișierului.\n");
        return 1;
    }

    //scrierea numelui si a prenumelui in fisierul csv cu virgula intre ele
    fprintf(file, "%s,%s\n", nume, prenume);
    fclose(file);

    //seteaza culoarea textului la verde
    printf("\033[38;5;40m");
    printf("Contul a fost creat cu succes.\n\n");
    printf("\033[38;5;207m");  //seteaza culoarea textului la roz mai inchis
    printf("Doriti sa va logati in contul dvs?\n\n");
    printf("------------------\n");
    printf("  1.Logare\n  2.Iesire\n");
    printf("------------------\n");
    scanf("%d",&opt);
      switch (opt) {
            case 1:
                logare(nume,prenume);
                break;
            case 2:
                return 0;
                break;
            default:
                printf("Optiune invalida.\n");
                break;
      }

};

