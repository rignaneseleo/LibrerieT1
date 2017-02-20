// Nome:
// Cognome:
// Matricola:

/*
Credits Librerie:
Leonardo Rignanese
*/

#include "function.h"

tipoArray leggi(char *fileName, int *dim) //di solito la lettura è così
{
    //ISTANZIO LE VARIABILI
    int i;
    FILE *file;
    tipoArray temp, *array;

    //INIZIALIZZO LE VARIABILI
    (*dim) = 0; //per sicurezza azzero la dimensione

    //APRO IL FILE
    file = fopen(fileName, "rt");

    //CONTROLLO SE CI SONO ERRORI NELL'APERTURA DEL FILE
    if (file != NULL)
    {
        //OTTENGO NUMERO RIGHE

        rewind(file); //rimetto il puntatore all'inizio del file

        //ALLOCO DINAMICAMENTE L'ARRAY
        array = (tipoArray *)malloc((*dim) * sizeof(tipoArray));

        //LEGGO LE RIGHE
        for (i = 0; i < *dim; i++)
        {
        }

        //CHIUDO IL FILE
        fclose(file);

        return array;
    }
    else
    {
        //errore apertura
        *dim = 0;
        return NULL;
    }
}

char readField(char buffer[], int dimBuffer, char sep, FILE *f)
{ // dopo aver utilizzato questa funzione, controllare il valore restituito: deve essere uguale al carattere separatore
    int i = 0;
    char ch = fgetc(f);
    while (ch != sep && ch != '\n' && ch != EOF && i < dimBuffer - 1)
    {
        buffer[i] = ch;
        i++;
        ch = fgetc(f);
    }
    buffer[i] = '\0';
    return ch;
}
