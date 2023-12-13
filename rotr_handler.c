#include "monty.h"

/**
 * rotr_handler - Rotates the stack to the bottom
 * @stack: Pointer to the stack
 * @line_num: Line number
 */
void rotr_handler(stack_t **stack, unsigned int line_num)
{
	stack_t *first, *last;

	(void)line_num;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = first;

		while (last->next)
			last = last->next;

		last->next = first;
		first->prev = last;
		*stack = last;
		last->prev->next = NULL;
		last->prev = NULL;
	}
}

