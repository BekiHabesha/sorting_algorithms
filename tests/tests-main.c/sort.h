#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - The Enumeration of Boolean values.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @false: It Equals 0.
 *
 * @true: It Equals 1.
 */

typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - The Doubly linked list node.
 *
 * Author: Bereket Dereje Mekonnen.
 *
 * @n: An Integer stored in the node
 *
 * @prev: A Pointer to the previous element
 *        of the list.
 *
 * @next: A Pointer to the next element
 *        of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void heap_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void bitonic_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif /* SORT_H_ */
