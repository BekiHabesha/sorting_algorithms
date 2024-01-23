/*
*
*  📝🔡File_name🔠📒: 104-heap_sort.c
*    📑🔢Task_no🔢📜: 8
* 📖🔤Task_Title🔤📃: Heap sort
*
*  📔📚Functions📓🗳: void heap_sort, void swap_ints,
*                       void max_heapify.
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

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - It Swaps two integers in an array.
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
 * max_heapify - It Turns a binary tree into
 *               a complete binary heap.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @array: An array of integers representing
 *         a binary tree.
 *
 * @size: The size of the array/tree.
 *
 * @base: The index of the base row of the tree.
 *
 * @root: The root node of the binary tree.
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}


/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort algorithm.
 *              It Prints the array after each swap.
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
