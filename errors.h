// Nome:
// Cognome:
// Matricola:

#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>

#define MALLOC_ERR 1
#define FOPEN_W_ERR 2
#define FOPEN_R_ERR 3
#define INVALID_ACCESS 4

int handleError(int err);    //Dato un intero da 1 a 4, stampa a video uno specifico errore
void exitWithError(int err); //Dato un intero da 1 a 4, stampa a video uno specifico errore e termina il programma

#endif
