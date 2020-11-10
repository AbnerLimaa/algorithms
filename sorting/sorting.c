#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sorting.h"

void insertion_sort(int* array, int size)
{
    if(array != NULL && size > 1)
    {
        for(int i = 1; i < size; i++)
        {
            int key = array[i];
            int j = i - 1;
            while(j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }
}

void merge(int* array, int p, int q, int r)
{
    if(array != NULL && p <= q && q <= r)
    {
        int size_left = q - p + 1;
        int size_right = r - q;
        int* left = (int*)calloc(size_left + 1, sizeof(int));
        int* right = (int*)calloc(size_right + 1, sizeof(int));
        if(left != NULL && right != NULL)
        {
            for(int i = 0; i < size_left; i++)
                left[i] = array[p + i];
            for(int j = 0; j < size_right; j++)
                right[j] = array[q + j + 1];
            int i = 0, j = 0;
            left[size_left] = __INT_MAX__;
            right[size_right] = __INT_MAX__;
            for(int k = p; k <= r; k++)
            {
                if(left[i] <= right[j])
                {
                    array[k] = left[i];
                    i++;
                }
                else
                {
                    array[k] = right[j];
                    j++;
                }
            }
        }
        if(left != NULL)
            free(left);
        if(right != NULL)
            free(right);
    }
}

void merge_sort_recursive(int *array, int p, int r)
{
    if(p < r)
    {
        int q = (p + r) >> 1;
        merge_sort_recursive(array, p, q);
        merge_sort_recursive(array, q + 1, r);
        merge(array, p, q, r);
    }
}

void merge_sort(int* array, int size)
{
    if(array != NULL && size > 1)
        merge_sort_recursive(array, 0, size - 1);
}