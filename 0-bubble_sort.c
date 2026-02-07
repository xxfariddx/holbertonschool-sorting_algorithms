#include <unistd.h>
#include "sort.h"

/**
 * _putchar - writes a character to stdout
 * @c: The character to write
 *
 * Return: 1 on success
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * print_array - prints an array of integers
 * @array: pointer to the array
 * @size: number of elements
 *
 * Description: Prints array elements separated by space, ends with newline.
 * Only handles positive integers.
 */
void print_array(int *array, size_t size)
{
    size_t i;
    int num, k, j;
    char buffer[10];

    for (i = 0; i < size; i++)
    {
        num = array[i];

        if (num == 0)
        {
            _putchar('0');
        }
        else
        {
            k = 0;
            while (num > 0)
            {
                buffer[k++] = (num % 10) + '0';
                num /= 10;
            }

            for (j = k - 1; j >= 0; j--)
                _putchar(buffer[j]);
        }

        if (i < size - 1)
            _putchar(' ');
    }

    _putchar('\n');
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: pointer to the array
 * @size: number of elements in the array
 *
 * Description: Prints the array after each swap
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

                print_array(array, size);

                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}
