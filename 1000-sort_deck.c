/*
*
*  📝🔡File_name🔠📒: 1000-sort_deck.c
*    📑🔢Task_no🔢📜: 12
* 📖🔤Task_Title🔤📃: Dealer
*
*  📔📚Functions📓🗳: void sort_deck, int _strcmp,
*                       char get_value,
*                       void insertion_sort_deck_kind
*                       void insertion_sort_deck_value
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

#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - It Compares two strings.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @s1: The first string to be compared.
 *
 * @s2: The second string to be compared.
 *
 * Return: Positive if byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative if byte difference if s1 < s2
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}


/**
 * get_value - It Gives the numerical value of a card.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */

char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}


/**
 * insertion_sort_deck_kind - Sort a deck of cards from
 *                            spades to diamonds.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @deck: A pointer to the head of a deck_node_t
 *        doubly-linked list.
 */

void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}


/**
 * insertion_sort_deck_value - It Sorts a deck of cards sorted
 *                             from spades to diamonds
 *                             from ace to king.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */

void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		       insert->card->kind == iter->card->kind &&
		       get_value(insert) > get_value(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}


/**
 * sort_deck - It Sorts a deck of cards
 *             from ace to king and
 *             from spades to diamonds.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @deck: A pointer to the head of a deck_node_t
 *        doubly-linked list.
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
