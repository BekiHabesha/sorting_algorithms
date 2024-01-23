/*
*
*  📝🔡File_name🔠📒: 105-radix_sort.c
*    📑🔢Task_no🔢📜: 9
* 📖🔤Task_Title🔤📃: Radix sort
*
*  📔📚Functions📓🗳: void radix_sort, int get_max,
*                       void radix_counting_sort
* 🗓⌚️Created On🕰📅: january 22, 2024
*
*     🧧🔠Project Title🔤🧰: 0x1B. C - Sorting algorithms & Big O
* 🗃📀GitHub repository📀💽: sorting_algorithms
*  💾🗂GitHub Directory📁🗃: sorting_algorithms
*
*  💻🖍️Author🖊️🪪: Bereket Dereje Mekkonen
*  🌍🔢Cohort🔢🌍: 19
* 🪙📱Program📲🎖: Full Stack
*
*/

#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - It Gives the maximum value in
 *           an array of integers.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */

int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}


/**
 * radix_counting_sort - It Sorts the significant digits of an
 *                       array of integers in ascending order
 *                       using the counting sort algorithm.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * @sig: The significant digit to sort on.
 *
 * @buff: A buffer to store the sorted array.
 */

void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}


/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm.
 *              It Prints the array after each
 *              significant digit increase.
 */

void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
