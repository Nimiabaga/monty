#include "monty.h"

/**
 * pop_handler - Remove the top element from the stack.
 * @stack: Pointer to the top of the stack.
 * @line_num: Line number in the file.
 */
void pop_handler(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		custom_free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}

