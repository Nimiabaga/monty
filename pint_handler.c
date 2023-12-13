#include "monty.h"

/**
 * pint_handler - Print the value at the top of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_num: Line number in the file.
 */
void pint_handler(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		custom_free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

