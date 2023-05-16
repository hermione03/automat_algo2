#include "tri.h"

void swap(hashMap *a, hashMap *b)
{
    hashMap t = *a;
    *a = *b;
    *b = t;
}

int partition(hashMap arr[], int low, int high)
{
    int pivot = arr[high].nb_occ;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // Change the comparison to >= to sort in descending order
        if (arr[j].nb_occ >= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(hashMap arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}