//HEADER GUARD
#pragma once

#include<stdio.h>
#include<string.h>

void readFromFile(const char* filePath, int* output);

void writeToFile(const char* filePath, const char* message);

void readFromCSV(const char* filePath);

int verificare_utilizator(const char* nume, const char* prenume);


FILE* openFile(const char* filePath, const char* mode);

void meniu(int op, char path[]);

void imprumutare_carti();

void vizualizare_imprumuturi(const char nume[], const char prenume[]);

void restituire_carti();

void donare_carti();

void vizualizare_carti();

int verificare_utilizator(const char* nume, const char* prenume);

void logare(const char* nume, const char* prenume);

void creare();

void cautare_carti1();

void cautare_carti2();

void antet();
