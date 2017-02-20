// Nome:
// Cognome:
// Matricola:

/*
Credits Librerie:
Leonardo Rignanese
*/

#include "array.h"

boolean type_arrEquals(tipoArray el1, tipoArray el2)
{
    //TODO restituire TRUE se due elementi sono CONSIDERATI uguali
    //NB: non necessariamente devono essere IDENTICI!
    //Es: Se in un array di persone bisogna rimuovere i parenti che hanno lo stesso cognome,
    //due elementi saranno uguali se hanno lo stesso cognome (il nome non viene considerato)
    printf("Configurami!\n");
    return 0;
}
int type_arrCompare(tipoArray el1, tipoArray el2)
{
    printf("Configurami!\n");
    if (type_arrEquals(el1, el2))
        return 0;
    else
    {
        //TODO restituire -1 se el1 viene prima di el2, 0 se e1==e2 e 1 se e2 viene prima di e1
    }
    return 0;
}
void type_arrSwap(tipoArray *a, tipoArray *b)
{
    tipoArray temp = *a;
    *a = *b;
    *b = temp;
}

/* RICERCA */
int searchFirst(tipoArray arr[], int dim, tipoArray el)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        if (type_arrEquals(el, arr[i]))
            return i;
    }
    return -1;
}

int searchLast(tipoArray arr[], int dim, tipoArray el)
{
    int i;
    for (i = dim - 1; i >= 0; i--)
    {
        if (type_arrEquals(el, arr[i]))
            return i;
    }
    return -1;
}

boolean inArray(tipoArray arr[], int dim, tipoArray el)
{
    int i;
    boolean found = FALSE;

    for (i = 0; i < dim && !found; i++)
    {
        if (type_arrEquals(el, arr[i]))
        {
            found = TRUE;
        }
    }
    return found;
}

int countRecurrance(tipoArray arr[], int dim, tipoArray el)
{
    int i, count = 0;
    for (i = 0; i < dim; i++)
    {
        if (type_arrEquals(el, arr[i]))
        {
            count++;
        }
    }
    return count;
}

int findMax(tipoArray arr[], int dim)
{
    int i, posMax = 0;

    for (i = 1; i < dim; i++)
        if (type_arrCompare(arr[posMax], arr[i]) < 0)
            posMax = i;
    return posMax;
}

int findMin(tipoArray arr[], int dim)
{
    int i, posMin = 0;

    for (i = 1; i < dim; i++)
        if (type_arrCompare(arr[posMin], arr[i]) > 0)
            posMin = i;
    return posMin;
}

/* CONFRONTO */
boolean compareEquals(tipoArray arr1[], int dim1, tipoArray arr2[], int dim2)
{
    int i;
    boolean uguali = TRUE;

    if (dim1 != dim2)
        return FALSE;

    for (i = 0; i < dim1 && uguali == TRUE; i++)
    {
        if (!type_arrEquals(arr1[i], arr2[i]))
        {
            uguali = FALSE;
        }
    }
    return uguali;
}

boolean compareUnordered(tipoArray arr1[], int dim1, tipoArray arr2[], int dim2)
{
    boolean *alreadyChecked;
    boolean uguali = TRUE;
    int i, j;

    if (dim1 != dim2)
        return FALSE;

    alreadyChecked = (boolean *)malloc(dim1 * sizeof(boolean));

    for (i = 0; i < dim1; i++)
        alreadyChecked[i] = FALSE;

    for (i = 0; i < dim1 && uguali; i++)
    {
        uguali = FALSE;

        for (j = 0; j < dim2 && !uguali; j++)
        {
            if (!alreadyChecked[j])
            {
                uguali = type_arrEquals(arr1[i], arr2[j]);
                if (uguali)
                {
                    alreadyChecked[j] = TRUE;
                }
            }
        }
    }

    free(alreadyChecked);
    return uguali;
}

/* ORDINAMENTO */
void naiveSort(tipoArray arr[], int dim)
{
    int p;
    while (dim > 1)
    {
        p = findMax(arr, dim);
        if (p < dim - 1)
            type_arrSwap(&arr[p], &arr[dim - 1]);
        dim--;
    }
}

void bubbleSort(tipoArray v[], int n)
{
    int i;
    boolean ordinato = FALSE;

    while (n > 1 && !ordinato)
    {
        ordinato = TRUE;
        for (i = 0; i < (n - 1); i++)
        {
            if (type_arrCompare(v[i], v[i + 1]) > 0)
            {
                type_arrSwap(&v[i], &v[i + 1]);
                ordinato = FALSE;
            }
        }
        n--;
    }
}

void insertSort(tipoArray v[], int n)
{
    int k;
    for (k = 1; k < n; k++)
        insOrd(v, k);
}

void insOrd(tipoArray v[], int pos)
{
    int i = pos - 1;
    tipoArray x = v[pos];
    while (i >= 0 && (type_arrCompare(x, v[i]) < 0))
    {
        v[i + 1] = v[i]; /* crea lo spazio */
        i--;
    }
    v[i + 1] = x; /* inserisce l�elemento */
}

void merge(tipoArray v[], int i1, int i2, int fine, tipoArray vout[])
{
    int i = i1, j = i2, k = i1;
    while (i <= i2 - 1 && j <= fine)
    {
        if (type_arrCompare(v[i], v[j]) < 0)
            vout[k] = v[i++];
        else
            vout[k] = v[j++];
        k++;
    }
    while (i <= i2 - 1)
    {
        vout[k] = v[i++];
        k++;
    }
    while (j <= fine)
    {
        vout[k] = v[j++];
        k++;
    }
    for (i = i1; i <= fine; i++)
        v[i] = vout[i];
}

void mergeSort(tipoArray v[], int first, int last, tipoArray vout[])
{
    int mid;
    if (first < last)
    {
        mid = (last + first) / 2;
        mergeSort(v, first, mid, vout);
        mergeSort(v, mid + 1, last, vout);
        merge(v, first, mid + 1, last, vout);
    }
}

void quickSort(tipoArray a[], int dim)
{
    quickSortR(a, 0, dim - 1);
}

void quickSortR(tipoArray a[], int iniz, int fine)
{
    int i, j, iPivot;
    tipoArray pivot;

    if (iniz < fine)
    {
        i = iniz;
        j = fine;
        iPivot = fine;
        pivot = a[iPivot];
        do /* trova la posizione del pivot */
        {
            while (i < j && type_arrCompare(a[i], pivot) <= 0)
                i++;
            while (j > i && type_arrCompare(a[j], pivot) >= 0)
                j--;
            if (i < j)
                type_arrSwap(&a[i], &a[j]);
        } while (i < j);
        /* posiziona il pivot */
        if (i != iPivot && type_arrCompare(a[i], a[iPivot]) != 0)
        {
            type_arrSwap(&a[i], &a[iPivot]);
            iPivot = i;
        }
        /* ricorsione sulle sottoparti, se necessario */
        if (iniz < iPivot - 1)
            quickSortR(a, iniz, iPivot - 1);
        if (iPivot + 1 < fine)
            quickSortR(a, iPivot + 1, fine);
    }
}
