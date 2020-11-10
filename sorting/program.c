#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

int* new_array(int size)
{
    if(size > 0)
    {
        int* array = (int*)calloc(size, sizeof(int));
        if(array != NULL)
        {
            srand(time(NULL));
            for(int i = 0; i < size; i++)
                array[i] = rand() % 1000;
            return array;
        }
    }
    return NULL;
}

void free_array(int* array)
{
    if(array != NULL)
    {
        free(array);
        array = NULL;
    }
}

void print_array(int* array, int size)
{
    if(array != NULL && size > 0)
    {
        printf("array = [");
        for(int i = 0; i < size; i++)
        {
            if((i + 1) == 100)
            {
                printf("... ]\n\t");
                break;
            }
            printf("%d", array[i]);
            if((i + 1) == size)
                printf("]");
            else
                printf("\t");
            if((i + 1) % 10 == 0)   
                printf("\n\t ");
        }
    }
}

int main(int argc, char** argv)
{
    int size;
    printf("Insert the array size\n");
    scanf("%d", &size);

    int* array = new_array(size);
    if(array != NULL)
    {
        int option;
        //int* sorted_array = NULL;
        int keep = 1;
        clock_t begin, end;
        print_array(array, size);
        printf("Choose one sorting algorithm.\n");
        printf("1 - Insertion sort;\n");
        printf("2 - Merge sort;\n");
        while(keep)
        {
            scanf("%d", &option);
            begin = clock();
            switch(option)
            {
                case 1: 
                    insertion_sort(array, size);
                    keep = 0;
                    break;
                case 2: 
                    merge_sort(array, size);
                    keep = 0;
                    break;
                default: printf("Wrong option\n");
                    break;
            }
            end = clock();
        }
        double running_time = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Total running time: %f s\n", running_time);
        print_array(array, size);
        free_array(array);   
    }
}