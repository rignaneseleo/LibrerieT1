#include "list.h"

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
		abort(); //TODO errore accesso invalido
	else 
		return l->value;
}

list tail(list l)
{
	if (empty(l))
		abort(); //TODO
	else 
		return l->next;
}

list cons(type_list el, list l)
{
	list t;
	t = (list)malloc(sizeof(node));
	if (t == NULL)
		abort(); //TODO
	t->value = el;
	t->next = l;
	return t;
}

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
		printf(FORMAT_TL, head(l));
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
		if (el == head(l))
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
	else if (el == head(l)) 
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

/* void sortList(list* l)
* -----------------------
* Implementazione di mergeSort per le linked lists.
* Non crea una copia della lista ma la ordina e basta
*
*/
void sortList(list* l)
{
	list a, b, head = *l;

	//Caso base: la lista � vuota o ha un elemento solo, quindi � gi� ordinata :)
	if (empty(*l) || tail(*l) == NULL)
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

	/* Caso base: se una delle due liste � vuota, l'unione � l'altra */
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
* La funzione divide la lista originale in due met� separate, che verranno inserite in @prima e @seconda.
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
		Cos� quando 'veloce' sar� giunto alla fine, 'lento' sar� a met�.*/

		while (!empty(veloce))
		{
			veloce = tail(veloce);
			if (!empty(veloce))
			{
				lento = tail(lento);
				veloce = tail(veloce);
			}
		}

		//la prima met� inizia dall'inizio (l)
		//la seconda met� inizia dopo il puntatore lento.

		*prima = l;
		*seconda = tail(lento);

		//Le due met� vengono divise eliminando il collegamento tra di esse
		lento->next = NULL;
	}
}