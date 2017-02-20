// Nome:
// Cognome:
// Matricola:

/*
Credits Librerie:
Leonardo Rignanese
*/

#ifndef LIST_H
#define LIST_H
#include "element.h"

typedef x tipoLista; //TODO Tipo degli elementi della lista

typedef struct list_element
{
    tipoLista value;
    struct list_element *next;
} item;

typedef item *list;

boolean elementEquals(tipoLista e1, tipoLista e2); //TODO da definire
int compareElement(tipoLista e1, tipoLista e2);    //TODO da definire

/* PRIMITIVE  */
list emptylist(void);
boolean empty(list);
list cons(tipoLista, list);
tipoLista head(list);
list tail(list);

/* NON PRIMITIVE  */
void freelist(list l);
boolean inList(tipoLista el, list l); //Verifica se l'elemento el � presente nella lista
int lengthList(list l);
list reverseList(list l); //Crea una copia della lista con l'ordine inverso //DEALLOCARE le liste passate!

list intersectList(list l1, list l2); // Riceve due liste e restituisce una nuova lista contenente i valori presenti in entrambe senza ripetizioni //DEALLOCARE le liste passate!
list diffList(list l1, list l2);      //Restituisce una nuova lista contenente i valori presenti in l1 che NON sono presenti in l2 senza ripetizioni //DEALLOCARE le liste passate!
list removeRepetitionList(list l);    //Restituisce una nuova lista senza ripetizioni //DEALLOCARE le liste passate!

/* ORDINAMENTO */
void sortList(list *l);                             //Funzione da utilizzare per l'ordinamento di una lista    //ATTENZIONE passare indirizzo con &
list mergeList(list a, list b);                     //Funzioni di appoggio per sortList
void splitList(list l, list *prima, list *seconda); //Funzioni di appoggio per sortList

#endif
