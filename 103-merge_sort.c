/*
*
*  📝🔡File_name🔠📒: 103-merge_sort.c
*    📑🔢Task_no🔢📜: 7
* 📖🔤Task_Title🔤📃: Merge sort
*
*  📔📚Functions📓🗳: void merge_sort, void merge_subarr,
*                       void merge_sort_recursive.
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

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - It Sorts a sub_array of integers.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @subarr: A sub_array of an array of integers to sort.
 *
 * @buff: A buffer to store the sorted subarray.
 *
 * @front: The front index of the array.
 *
 * @mid: The middle index of the array.
 *
 * @back: The back index of the array.
 */

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}


/**
 * merge_sort_recursive - It Implement the merge sort
 *                        algorithm through recursion.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @subarr: A subarray of an array of integers to sort.
 *
 * @buff: A buffer to store the sorted result.
 *
 * @front: The front index of the subarray.
 *
 * @back: The back index of the subarray.
 */

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}


/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
