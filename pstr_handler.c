#include "monty.h"

/**
 * pstr_handler - Prints the string starting from the top of the stack
 * @stack: Pointer to the head of the stack
 * @line_num: Line number of the opcode in the Monty file
 */
void pstr_handler(stack_t **stack, unsigned int line_num)
{
	stack_t *current_node;
	(void)line_num;

	current_node = *stack;
	while (current_node)
	{
		if (current_node->n > 127 || current_node->n <= 0)
		{
			break;
		}
		printf("%c", current_node->n);
		current_node = current_node->next;
	}
	printf("\n");
}

