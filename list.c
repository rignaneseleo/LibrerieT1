// Nome:
// Cognome:
// Matricola:

/*
Credits Librerie:
Leonardo Rignanese
*/

#include "list.h"

boolean elementEquals(tipoLista e1, tipoLista e2)
{
    //TODO restituire TRUE se due elementi sono CONSIDERATI uguali
    //NB: non necessariamente devono essere IDENTICI!
    //Es: Se in una lista di persone bisogna rimuovere i parenti che hanno lo stesso cognome,
    //due elementi saranno uguali se hanno lo stesso cognome (il nome non viene considerato)
    printf("Configurami!\n");
    return 0;
}

int compareElement(tipoLista e1, tipoLista e2)
{
    //TODO quale dei due elementi viene prima? -1 se il primo viene prima, 1 se il secondo viene prima,0 se sono uguali
    printf("Configurami!\n");
    return 0;
}

/* OPERAZIONI PRIMITIVE */
list emptylist() /* costruttore lista vuota */
{
    return NULL;
}
boolean empty(list l) /* verifica se lista vuota */
{
    return (l == NULL);
}

list cons(tipoLista e, list l) /* costruttore che aggiunge in testa alla lista */
{
    list t;
    t = (list)malloc(sizeof(item));
    t->value = e;
    t->next = l;
    return (t);
}

tipoLista head(list l) /* selettore testa lista */
{
    if (empty(l))
        exit(-2);
    else
        return (l->value);
}

list tail(list l) /* selettore coda lista */
{
    if (empty(l))
        exit(-1);
    else
        return (l->next);
}

//NON PRIMITIVE
void freelist(list l)
{
    if (empty(l))
    {
        return;
    }
    else
    {
        freelist(tail(l));
        free(l);
    }
    return;
}

boolean inList(tipoLista el, list l)
{
    boolean trovato = FALSE;
    while (!empty(l) && !trovato)
    {
        if (elementEquals(el, head(l)))
            trovato = TRUE;
        else
            l = tail(l);
    }
    return trovato;
}

int lengthList(list l)
{
    int n = 0;
    while (!empty(l))
    {
        n++;
        l = tail(l);
    }
    return n;
}

list reverseList(list l)
{
    list temp = emptylist();
    /*
     list l1c;
     l1c=l;
     */
    while (!empty(l))
    {
        temp = cons(head(l), temp);
        l = tail(l);
    }

    printf("\nFREE necessaria\n");
    /*
     freelist(l1c);
     */
    return temp;
}

list intersectList(list l1, list l2)
{
    tipoLista cur;
    list intersection = emptylist();
    /*
     list l1c,l2c;
     l1c=l1;
     l2c=l2;
     */
    while (!empty(l1))
    {
        cur = head(l1);
        if (inList(cur, l2) && !inList(cur, intersection))
            intersection = cons(cur, intersection);
        l1 = tail(l1);
    }
    /*
     freelist(l1c);
     freelist(l2c);
     */
    printf("\nFREE necessaria\n");
    return intersection;
}

list diffList(list l1, list l2)
{
    tipoLista cur;
    list difference = NULL, temp;
    /*
     list l1c,l2c;
     l1c=l1;
     l2c=l2;
     */
    while (!empty(l1))
    {
        cur = head(l1);
        if (!inList(cur, l2) && !inList(cur, difference))
        {
            temp = (list)malloc(sizeof(item)); 
            temp->value = cur;
            temp->next = difference;
            difference = temp;
        }
        l1 = tail(l1);
    }
    /*
     freelist(l1c);
     freelist(l2c);
     */
    printf("\nFREE necessaria\n");
    return difference;
}

list removeRepetitionList(list l)
{
    /*
  list r=intersectList(l, l);
  freelist(l);
  return r;
  */
    return intersectList(l, l);
}

/* void sortList(list* l)
 * -----------------------
 * Implementazione di mergeSort per le liste.
 * Non crea una copia della lista ma la ordina e basta
 * Non alloca ne libera alcuna memoria e ha velocit� O( n*logn )
 */
void sortList(list *l)
{
    list a, b, head = *l;

    //Caso base: la lista e' vuota o ha un elemento solo, quindi e' gia' ordinata :)
    if (empty(*l) || empty(tail(*l)))
    {
        return;
    }
    else
    {
        //dividi
        splitList(head, &a, &b);
        //et impera
        sortList(&a);
        sortList(&b);

        //Merge delle liste ordinate nella lista originale
        *l = mergeList(a, b);
    }
}

list mergeList(list a, list b)
{
    list merged = emptylist();

    /* Caso base: se una delle due liste e' vuota, l'unione e' l'altra */
    if (empty(a))
        return b;
    else if (empty(b))
        return a;

    /* PER ORDINARE  */
    if (compareElement(head(a), head(b)) <= 0)
    {
        merged = a;
        merged->next = mergeList(tail(a), b);
    }
    else
    {
        merged = b;
        merged->next = mergeList(a, tail(b));
    }

    printf("\nFREE necessaria\n");
    return merged;
}

/* void splitList(list l, list* prima, list* seconda)
 * --------------------------------------------------
 * Prende come argomenti la lista originale @l, e due liste (@prima e @seconda) per riferimento.
 * La funzione divide la lista originale in due meta' separate, che verranno inserite in @prima e @seconda.
 */
void splitList(list l, list *prima, list *seconda)
{
    list veloce;
    list lento;
    if (empty(l) || empty(tail(l)))
    {
        *prima = l;
        *seconda = emptylist();
    }
    else
    {
        lento = l;
        veloce = tail(l);

        /* 'veloce' avanza di 2 nodi, 'lento' avanza di 1 nodo.
         Cosi' quando 'veloce' sara' giunto alla fine, 'lento' sara' a meta'.*/

        while (!empty(veloce))
        {
            veloce = tail(veloce);
            if (!empty(veloce))
            {
                lento = tail(lento);
                veloce = tail(veloce);
            }
        }

        //la prima meta' inizia dall'inizio (l)
        //la seconda meta' inizia dopo il puntatore lento.

        *prima = l;
        *seconda = tail(lento);

        //Le due meta' vengono divise eliminando il collegamento tra di esse
        lento->next = NULL;
    }
}
