
void vizualizare_carti()
{

        printf("\033[38;5;225m");//mov mai deschis
    printf("Carti disponibile:\n\n");
    readFromCSV("data.csv");
    printf("\n");

            printf("\033[38;5;207m");//Setarea culorii textului la mov

};
