#include "monty.h"

/**
 * print_stack - Print all values in the stack.
 * @stack: Pointer to the top of the stack.
 * @line_num: Line number in the file (unused in this function).
 */
void print_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *current_node;
	(void)line_num;

	current_node = *stack;
	if (current_node == NULL)
	{
		/* Stack is empty, no values to print */
		return;
	}

	/* Loop through the stack and print values */
	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

