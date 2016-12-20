// Nome:
// Cognome:
// Matricola:

#include "array.h"

/* RICERCA */
int searchFirst(type_arr arr[], int dim, type_arr el)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        if (type_arrEquals(el, arr[i]))
            return i;
    }
    return -1;
}

int searchLast(type_arr arr[], int dim, type_arr el)
{
    int i;
    for (i = dim - 1; i >= 0; i--)
    {
        if (type_arrEquals(el, arr[i]))
            return i;
    }
    return -1;
}

boolean inArray(type_arr arr[], int dim, type_arr el)
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

int countRecurrance(type_arr arr[], int dim, type_arr el)
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

int findMax(type_arr arr[], int dim)
{
    int i, posMax = 0;

    for (i = 1; i < dim; i++)
        if (type_arrCompare(arr[posMax], arr[i]) < 0)
            posMax = i;
    return posMax;
}

int findMin(type_arr arr[], int dim)
{
    int i, posMin = 0;

    for (i = 1; i < dim; i++)
        if (type_arrCompare(arr[posMin], arr[i]) > 0)
            posMin = i;
    return posMin;
}

/* CONFRONTO */
boolean compareEquals(type_arr arr1[], int dim1, type_arr arr2[], int dim2)
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

boolean compareUnordered(type_arr arr1[], int dim1, type_arr arr2[], int dim2)
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
void naiveSort(type_arr arr[], int dim)
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

void bubbleSort(type_arr v[], int n)
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

void insertSort(type_arr v[], int n)
{
    int k;
    for (k = 1; k < n; k++)
        insOrd(v, k);
}

void insOrd(type_arr v[], int pos)
{
    int i = pos - 1;
    type_arr x = v[pos];
    while (i >= 0 && (type_arrCompare(x, v[i]) < 0))
    {
        v[i + 1] = v[i]; /* crea lo spazio */
        i--;
    }
    v[i + 1] = x; /* inserisce l�elemento */
}

void merge(type_arr v[], int i1, int i2, int fine, type_arr vout[])
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

void mergeSort(type_arr v[], int first, int last, type_arr vout[])
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

void quickSort(int a[], int dim)
{
    quickSortR(a, 0, dim - 1);
}

void quickSortR(type_arr a[], int iniz, int fine)
{
    int i, j, iPivot;
    type_arr pivot;

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

/* ALTRO */
void showArray(type_arr arr[], int dim)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        type_arrPrint(arr[i]);
    }
}
