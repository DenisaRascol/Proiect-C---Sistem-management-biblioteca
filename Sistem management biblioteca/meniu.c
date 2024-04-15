
void meniu(int op, char path[])
{
  int optiune;
  char nume[100],prenume[100];
    switch(op)
    {
    case 1:
            printf("\033[38;5;225m");//mov mai deschis
            printf("Optiuni:\n\n");
            printf("1. Imprumuta Carti\n");
            printf("2. Vizualizare imprumuturi efectuate\n\n");
            printf("Introduceti optiunea: ");
            scanf("%d", &optiune);
            printf("\n");
            switch (optiune) {
                case 1:
                    imprumutare_carti(nume,prenume);
                    break;
                case 2:
                    // Citim numele și prenumele utilizatorului
                    printf("Introduceti numele si prenumele: ");
                    scanf("%s %s", nume, prenume);
                    vizualizare_imprumuturi(nume, prenume);
                    break;
                default:
                    printf("\033[1;31m"); //setarea textului la culoarea roșie
                    printf("Optiune invalida.\n");
            }
            break;
    case 2:
            printf("\033[38;5;225m");//mov mai deschis
            printf("Optiuni:\n\n");
            printf("1. Restituire carti\n");
            printf("2. Donare carti(act de donatie) \n\n");
            printf("Introduceti optiunea: ");
            scanf("%d", &optiune);
            printf("\n");
            switch (optiune) {
                case 1:
                    restituire_carti();
                    break;
                case 2:
                    donare_carti();
                    break;
                default:
                    printf("\033[1;31m"); //setarea textului la culoarea roșie
                    printf("Optiune invalida.\n");
            }
            break;
    case 3:
        vizualizare_carti();
        break;
    case 4:
            printf("\033[38;5;225m");//mov mai deschis
            printf("Optiuni de cautare:\n\n");
            printf("1. Cautare dupa Titlu sau Autor\n");
            printf("2. Cautare dupa Titlu si Autor\n\n");
            printf("Introduceti optiunea: ");
            scanf("%d", &optiune);
            printf("\n");
            switch (optiune) {
                case 1:
                    cautare_carti1();
                    break;
                case 2:
                    cautare_carti2();
                    break;
                default:
                    printf("\033[1;31m"); //setarea textului la culoarea roșie
                    printf("Optiune invalida.\n");
            }
            break;

    case 0:
        printf("EXIT!");
        break;
    default:
        printf("\033[1;31m"); //setarea textului la culoarea roșie
        printf("Optiune invalida.\n");
    }
}

