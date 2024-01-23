/*
*
*  📝🔡File_name🔠📒: 2-selection_sort.c
*    📑🔢Task_no🔢📜: 2
* 📖🔤Task_Title🔤📃: Selection sort
*
*  📔📚Functions📓🗳: void selection_sort, void swap_ints.
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
 * selection_sort - Sort an array of integers in
 *                  ascending order using the
 *                  selection sort algorithm.
 *
 * Author: Bereket Dereje Mekkonnen.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
