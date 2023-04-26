#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * compare_cards - Compare two cards in a deck
 *
 * @a: A pointer to a pointer to the first card to compare
 * @b: A pointer to a pointer to the second card to compare
 * 
 * Return: The result of the comparison between the two cards
 */
int compare_cards(const void *a, const void *b)
{
    const card_t *card_a = (*(const deck_node_t **)a)->card;
    const card_t *card_b = (*(const deck_node_t **)b)->card;

    int value_cmp = strcmp(card_a->value, card_b->value);

    if (value_cmp != 0) {
        return value_cmp;
    } else {
        return card_a->kind - card_b->kind;
    }
}

/**
 * sort_deck - Sort a deck of cards
 *
 * @deck_: A pointer to a pointer to the head of the deck to sort
 *
 *Return: no return
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *node_ptrs[52];
    deck_node_t *curr_node = *deck;
    int i;

    for (i = 0; i < 52; i++) {
        node_ptrs[i] = curr_node;
        curr_node = curr_node->next;
    }

    qsort(node_ptrs, 52, sizeof(deck_node_t *), compare_cards);

    for (i = 0; i < 51; i++) {
        node_ptrs[i]->next = node_ptrs[i+1];
        node_ptrs[i+1]->prev = node_ptrs[i];
    }
    node_ptrs[0]->prev = NULL;
    node_ptrs[51]->next = NULL;
    *deck = node_ptrs[0];
}
