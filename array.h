// Nome:
// Cognome:
// Matricola:

/*
Credits Librerie:
Leonardo Rignanese
*/

#ifndef array_h
#define array_h

#include <stdio.h>
#include "element.h"

typedef x tipoArray; //TODO Tipo degli elementi dell'array

boolean type_arrEquals(tipoArray el1, tipoArray el2); //TODO da definire
int type_arrCompare(tipoArray el1, tipoArray el2);    //TODO da definire

/* RICERCA */
int searchFirst(tipoArray arr[], int dim, tipoArray el);     //Resistuisce la prima posizione dell'elemento el nell'array, -1 se non è presente
int searchLast(tipoArray arr[], int dim, tipoArray el);      //Resistuisce l'ultima posizione dell'elemento el nell'array, -1 se non è presente
boolean inArray(tipoArray arr[], int dim, tipoArray el);     //TRUE se el è presente nell'array, altrimenti FALSE
int countRecurrance(tipoArray arr[], int dim, tipoArray el); //Conta quante volte l'elemento el è presente nell'array

int findMax(tipoArray arr[], int dim); //Trova la posizione dell'elemento massimo
int findMin(tipoArray arr[], int dim); //Trova la posizione dell'elemento minimo

/* CONFRONTO */
boolean compareEquals(tipoArray arr1[], int dim1, tipoArray arr2[], int dim2);    //Controlla se due array sono uguali (hanno gli stessi elementi nello stesso ordine)
boolean compareUnordered(tipoArray arr1[], int dim1, tipoArray arr2[], int dim2); //Controlla se due array hanno gli stessi elementi in ordine diverso

/* ORDINAMENTO */
void naiveSort(tipoArray arr[], int dim);
void bubbleSort(tipoArray v[], int n);
void insOrd(tipoArray v[], int pos);
void insertSort(tipoArray v[], int n);
void quickSort(tipoArray a[], int dim);
void quickSortR(tipoArray a[], int iniz, int fine);

#endif /* array_h */
