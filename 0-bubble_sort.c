#include <stdio.h>
#include <stddef.h>

/* Prototype */
void bubble_sort(int *array, size_t size);

/* Helper function to print the array */
void print_array(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/* Bubble Sort implementation */
void bubble_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int swapped;

    for (size_t i = 0; i < size - 1; i++)
    {
        swapped = 0;

        for (size_t j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                /* Swap elements */
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                /* Print array after each swap */
                print_array(array, size);

                swapped = 1;
            }
        }

        /* If no swaps happened in inner loop, array is sorted */
        if (swapped == 0)
            break;
    }
}
