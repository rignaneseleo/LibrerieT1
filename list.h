// Nome:
// Cognome:
// Matricola:

#include "element.h"

#ifndef LIST_H
#define LIST_H

typedef struct list_element
{
    type_list value;
    struct list_element *next;
} node;

typedef node *list;

/* PRIMITIVE */

list emptyList();                //Restituisce lista vuota
boolean empty(list l);           //Verifica se lista vuota
type_list head(list l);          //Restituisce il valore del primo elemento della lista
list tail(list l);               //Restituisce un puntatore alla coda della lista
list cons(type_list el, list l); //Inserisce il valore el in testa alla lista l

/* NON PRIMITIVE */

void freeList(list l);                 //Dealloca la memoria della lista
void showList(list l);                 //Stampa la lista
boolean inList(type_list el, list l);  //Verifica se l'elemento el � presente nella lista
int lengthList(list l);                //Restituisce il numero di nodi della lista
list copyList(list l);                 //Restituisce una copia della lista l
list appendList(list l1, list l2);     //Concatena la lista l2 alla lista l1
list reverseList(list l);              //Crea una copia della lista con l'ordine inverso
list deleteNode(type_list el, list l); //Crea una nuova lista senza l'elemento el
list subList(int n, list l);           //Restituisce una lista a partire dall'elemento in posizione n (a partire da 0)
list intersectList(list l1, list l2);  // Riceve due liste e restituisce una nuova lista contenente i valori presenti in entrambe senza ripetizioni
list diffList(list l1, list l2);       //Restituisce una nuova lista contenente i valori presenti in l1 che NON sono presenti in l2 senza ripetizioni
list removeRepetitionList(list l);     //Restituisce una nuova lista senza ripetizioni

/* ORDINAMENTO */

void sortList(list *l);                             //Funzione da utilizzare per l'ordinamento di una lista    //ATTENZIONE passare indirizzo con &
list mergeList(list a, list b);                     //Funzioni di appoggio per sortList
void splitList(list l, list *prima, list *seconda); //Funzioni di appoggio per sortList

#endif
