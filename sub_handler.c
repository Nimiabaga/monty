#include "monty.h"

/**
 * sub_handler - Subtract the top element from
 * the second top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_num: Line number in the file.
 */
void sub_handler(stack_t **stack, unsigned int line_num)
{
	stack_t *current_top;
	int subtraction_result, num_nodes;

	current_top = *stack;

	/* Count the number of nodes in the stack */
	for (num_nodes = 0; current_top != NULL; num_nodes++)
		current_top = current_top->next;

	if (num_nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		custom_free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	/* Perform subtraction and update the stack */
	current_top = *stack;
	subtraction_result = current_top->next->n - current_top->n;
	current_top->next->n = subtraction_result;
	*stack = current_top->next;

	/* Remove the top element from the stack */
	free(current_top);
}

