#include "monty.h"

/**
 * mul_handler - Multiply the second top element
 * with the top element of the stack.
 * @head: Pointer to the top of the stack.
 * @line_num: Line number in the file.
 */
void mul_handler(stack_t **head, unsigned int line_num)
{
	stack_t *current_top;
	int result, num_nodes;

	current_top = *head;

	/* Count the number of nodes in the stack */
	for (num_nodes = 0; current_top != NULL; num_nodes++)
		current_top = current_top->next;

	if (num_nodes < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		custom_free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current_top = *head;
	result = current_top->next->n * current_top->n;

	/* Update the stack */
	current_top->next->n = result;
	*head = current_top->next;

	/* Remove the top element from the stack */
	free(current_top);
}

