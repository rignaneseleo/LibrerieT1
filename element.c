// Nome:
// Cognome:
// Matricola:

#include "element.h"


/* ELEMENT */

int elementCompare(element a, element b) //TODO : in base al criterio dato, definisci quale tra a e b viene prima
{
    //Per numeri e char
    return a - b;

    //Per le stringhe
    // return strcmp(a, b);

    /*
	NOTA BENE:
	La funzione deve restituire:
	- un numero POSITIVO se a viene prima di b
	- un numero NEGATIVO se b viene prima di a
	- 0 se a e b sono uguali
	*/
}

boolean elementEquals(element a, element b) //TODO : in base al criterio dato, definisci se a e b sono condiderate uguali
{
    return (a == b); //DA MODIFICARE A SECONDA DI ELEMENT
}


/* ARRAY */

int type_arrCompare(type_arr a, type_arr b)
{
	//Se element e type_arr UGUALI
	return elementCompare(a, b);

	//Se element e type_arr DIVERSI
	//TODO : in base al criterio dato, definisci quale tra a e b viene prima	
}

boolean type_arrEquals(type_arr a, type_arr b) 
{
	//Se element e type_arr UGUALI
	return elementEquals(a, b); 
	
	//Se element e type_arr DIVERSI
	//TODO : in base al criterio dato, definisci se a e b sono considerate uguali
}

void type_arrSwap(type_arr *a, type_arr *b)
{
	type_arr temp = *a;
	*a = *b;
	*b = temp;
}

void type_arrFPrint(FILE* f, type_arr a) //TODO//
{
	fprintf(f, FORMAT_TA, a); //CAMBIARE LE VARIABILI
}

void type_arrPrint(type_arr a)
{
	type_arrFPrint(stdout, a);//stampa in console
}


/* LISTE */

int type_listCompare(type_list a, type_list b) 
{
	//Se element e type_list UGUALI
	return elementCompare(a, b);

	//Se element e type_list DIVERSI
	//TODO : in base al criterio dato, definisci quale tra a e b viene prima	
}

boolean type_listEquals(type_list a, type_list b)
{
	//Se element e type_list UGUALI
	return elementEquals(a, b);

	//Se element e type_list DIVERSI
	//TODO : in base al criterio dato, definisci se a e b sono considerate uguali
}

void type_listSwap(type_list *a, type_list *b)
{
	type_list temp = *a;
	*a = *b;
	*b = temp;
}

void type_listFPrint(FILE* f, type_list a) 
{
	fprintf(f, FORMAT_TL, a);
}

void type_listPrint(type_list a)
{
	type_listFPrint(stdout, a);
}
