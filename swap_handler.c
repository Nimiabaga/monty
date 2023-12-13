#include "monty.h"

/**
 * swap_handler - Swap the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_num: Line number in the file.
 */
void swap_handler(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *next;
	int temp_value;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		custom_free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	next = top->next;
	temp_value = top->n;

	/* Swap the values of the top two elements */
	top->n = next->n;
	next->n = temp_value;
}

