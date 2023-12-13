#include "monty.h"
/**
 * free_stack - Frees the linked list.
 * @stack: Pointer to the head of the list.
 */
void custom_free_stack(stack_t *stack)
{
	stack_t *current;

	current = stack;

	while (current)
	{
		stack_t *next_node = current->next;

		free(current);
		current = next_node;
	}
}

