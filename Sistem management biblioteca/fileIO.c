#include "fileIO.h"

void readFromCSV(const char* filePath)
{
    FILE* file = openFile(filePath, "r");

    if (file == NULL)
        return;

    char header[100];
    char data[100];

    char* token;

    fgets(header, 100, file);

    while (fgets(data, 100, file) != NULL) // Citeste fiecare linie pana la sfarsitul fisierului
    {
        if (strlen(data) <= 1) // Daca linia este goala, sarim peste ea
            continue;

        token = strtok(data, ",");
        if (token != NULL)
        {
            printf("Titlu: %s ; ", token);
            token = strtok(NULL, ",");
        }
        if (token != NULL)
        {
            printf("Autor: %s ; ", token);
            token = strtok(NULL, ",");
        }
        if (token != NULL)
        {
            printf("Numar exemplare: %s\n", token);
        }
    }

    fclose(file);
}


void readFromFile(const char* filePath, int* output)
{
    if(output == NULL)
        return;

    FILE* file = openFile(filePath, "r");

    if(file == NULL)
        return;

    fscanf_s(file, "%d", output);
    fclose(file);
}

void writeToFile(const char* filePath, const char* message)
{
    if(message == NULL || strlen(message) == 0)
        return;

    FILE* file = openFile(filePath, "w");

    if(file == NULL)
        return;

    fprintf(file, "%s", message);
    fclose(file);
}

FILE* openFile(const char* filePath, const char* mode)
{
    if(filePath == NULL || strlen(filePath)== 0 ||
       mode == NULL || strlen(mode) == 0)
       return NULL;

    FILE* file = NULL;

    fopen_s(&file, filePath, mode);
    return file;
}
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // șterge caracterele rămase din buffer
}
