// Nome:
// Cognome:
// Matricola:

#include "list.h"

/* PRIMITIVE */

list emptyList() 
{
	return NULL;
}

boolean empty(list l)
{
	if (l == NULL)
		return TRUE; 
	else 
		return FALSE;
}

type_list head(list l)
{
	if (empty(l))
    {
        handleError(INVALID_ACCESS);
        exit(INVALID_ACCESS);
    }
	else
    {
		return l->value;
    }
}

list tail(list l)
{
	if (empty(l))
    {
        handleError(INVALID_ACCESS);
        exit(INVALID_ACCESS);
    }
	else 
		return l->next;
}

list cons(type_list el, list l)
{
	list t;
	t = (list)malloc(sizeof(node));
	if (t == NULL)
    {
        handleError(INVALID_ACCESS);
        exit(INVALID_ACCESS);
    }
    
	t->value = el;
	t->next = l;
	return t;
}

/* PRIMITIVE */

void freeList(list l)
{
	list temp = l;
	if (!empty(temp))
	{
		temp = tail(l);
		free(l);
		freeList(temp);
	}
}

void showList(list l)
{
	printf("[");
	while (!empty(l)) 
	{
		type_listPrint( head(l) );
		l = tail(l);
		if (!empty(l)) 
			printf(", ");
	} 
	printf("]\n");
}

boolean inList(type_list el, list l)
{
	while (!empty(l)) 
	{
		if ( type_listEquals(el,head(l)) )
			return TRUE;
		else
			l = tail(l);
	} 
	return FALSE;
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

list copyList(list l) 
{
	if (empty(l))
		return l;
	else 
		return cons(head(l), copyList(tail(l)));
}

list appendList(list l1, list l2)
{
	if (empty(l1))
		return copyList(l2);
	else
		return cons(head(l1), appendList(tail(l1), copyList(l2)));
}

list reverseList(list l) 
{
	if (empty(l))
		return emptyList();
	else 
		return appendList(reverseList(tail(l)), cons(head(l), emptyList()));
}

list deleteNode(type_list el, list l) 
{
	if (empty(l))
		return emptyList();
	else if ( type_listEquals(el, head(l))) 
		return copyList(tail(l));
	else 
		return cons(head(l), deleteNode(el, tail(l)));
}

list subList(int n, list l)
{
	int i = 0;
	while ((l != NULL) && (i < n))
	{
		l = l->next; 
		i++;
	}
	return l;
}

list intersectList(list l1, list l2)
{
	type_list cur;
	list intersection = emptyList();
	while (!empty(l1))
	{
		cur = head(l1);
		if (inList(cur, l2) && !inList(cur, intersection))
			intersection = cons(cur, intersection);
		l1 = tail(l1);
	}
	return intersection;
}

list diffList(list l1, list l2) {
	type_list cur;
	list difference = NULL, temp;
	while (!empty(l1))
	{
		cur = head(l1);
		if (!inList(cur,l2) && !inList(cur, difference))
		{
			temp = (list)malloc(sizeof(node));
			temp->value = cur;
			temp->next = difference;
			difference = temp;
		}
		l1 = tail(l1);
	}
	return difference;
}

list removeRepetitionList(list l)
{
	return intersectList(l, l);
}

/* void sortList(list* l)
* -----------------------
* Implementazione di mergeSort per le liste.
* Non crea una copia della lista ma la ordina e basta
* Non alloca ne libera alcuna memoria e ha velocit� O( n*logn )
*/
void sortList(list* l)
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
	list merged = emptyList();

	/* Caso base: se una delle due liste e' vuota, l'unione e' l'altra */
	if (empty(a))
		return b;
	else if (empty(b))
		return a;

	/* PER ORDINARE  */
	if (type_listCompare(head(a), head(b)) <= 0)
	{
		merged = a;
		merged->next = mergeList(tail(a), b);
	}
	else
	{
		merged = b;
		merged->next = mergeList(a, tail(b));
	}
	return merged;
}

/* void splitList(list l, list* prima, list* seconda)
* --------------------------------------------------
* Prende come argomenti la lista originale @l, e due liste (@prima e @seconda) per riferimento.
* La funzione divide la lista originale in due meta' separate, che verranno inserite in @prima e @seconda.
*/
void splitList(list l, list* prima, list* seconda)
{
	list veloce;
	list lento;
	if (empty(l) || empty(tail(l)))
	{
		*prima = l;
		*seconda = emptyList();
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
