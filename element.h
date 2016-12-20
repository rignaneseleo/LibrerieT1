// Nome:
// Cognome:
// Matricola:

#ifndef ELEMENT_H
#define ELEMENT_H

#include "common.h"

#define FORMAT_TA "%d" //TODO Inserire la stringa di formato per stampare gli elementi di tipo type_arr
#define FORMAT_TL "%d" //TODO Inserire stringa di formato per stampare gli elementi di tipo type_list

/* DEFINIZIONE DEI TIPI */

typedef int element;       //E' il tipo della variabile base				//TODO Sostituire con il tipo voluto per la variabile base
typedef element type_arr;  //E' il tipo degli elementi dell'array			//TODO Sostituire con il tipo voluto per l'array
typedef element type_list; //E' il tipo degli elementi value della lista	//TODO Sostituire con il tipo voluto per la lista

/* ELEMENT */

int elementCompare(element a, element b);    //Definisce quale tra le due variabili di tipo element 'viene prima' (non è sempre detto che sia la maggiore, dipende dal criterio)
boolean elementEquals(element a, element b); //Dati due variabili di tipo element, restituisce true se le due sono considerate uguali

/* ARRAY */

int type_arrCompare(type_arr a, type_arr b);    //Confronto tra due elementi di tipo type_arr
boolean type_arrEquals(type_arr a, type_arr b); //Verifico se due elementi di tipo type_arr sono uguali
void type_arrSwap(type_arr *a, type_arr *b);    //Scambio i puntatori a due elementi type_arr
void type_arrPrint(type_arr a);                 //Stampo un elemento di tipo type_arr
void type_arrFPrint(FILE *stream, type_arr a);  //Stampo a file un elemento di tipo type_arr

/* LISTE */

int type_listCompare(type_list a, type_list b);    //Confronto tra due elementi di tipo type_list
boolean type_listEquals(type_list a, type_list b); //Verifico se due elementi di tipo type_list sono uguali
void type_listSwap(type_list *a, type_list *b);    //Scambio i puntatori a due elementi type_list
void type_listPrint(type_list a);                  //Stampo un elemento di tipo type_list
void type_listFPrint(FILE *stream, type_list a);   //Stampo a file un elemento di tipo type_list

#endif
