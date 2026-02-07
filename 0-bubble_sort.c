#include "sort.h"

/**
 * print_array - prints the elements of an array
 * @array: the array to print
 * @size: number of elements
 */
void print_array(int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
    {
        /* Use standard output functions if allowed */
        /* Here, just example: you might replace with write() in strict projects */
        _putchar(array[i] + '0'); /* Example placeholder */
    }
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: the array to sort
 * @size: number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int swapped;
    int temp;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;

        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                /* Print array after each swap */
                print_array(array, size);

                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}
