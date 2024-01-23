/*
*
*  📝🔡File_name🔠📒: 100-shell_sort.c
*    📑🔢Task_no🔢📜: 4
* 📖🔤Task_Title🔤📃: Shell sort - Knuth Sequence
*
*  📔📚Functions📓🗳: void shell_sort, void swap_ints.
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

/**
 * swap_ints - Swap two integers in an array.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @a: The first integer to swap.
 *
 * @b: The second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
