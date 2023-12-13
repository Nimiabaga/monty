#include "monty.h"

/**
 * rotl_handler - Rotates the stack to the top
 * @stack: Pointer to the stack
 * @line_num: Line number
 */
void rotl_handler(stack_t **stack, unsigned int line_num)
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
		*stack = first->next;
		(*stack)->prev = NULL;
		first->next = NULL;
	}
}

