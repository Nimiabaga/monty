#include "monty.h"

/**
 * add_handler - Your function implementation
 * @stack: The stack
 * @line_num: Line number
 */
void add_handler(stack_t **stack, unsigned int line_num)

{
	stack_t *top, *second_top;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
	  custom_free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second_top = top->next;
	result = top->n + second_top->n;

	/* Store the result in the second top element */
	second_top->n = result;

	/* Remove the top element from the stack */
	*stack = second_top;
	free(top);

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
}

