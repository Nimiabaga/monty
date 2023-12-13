#include "monty.h"

/**
 * div_handler - Divides the second top element of the stack by the top element
 * @stack: Pointer to the head of the stack
 * @line_num: Line number of the opcode in the Monty file
 */
void div_handler(stack_t **stack, unsigned int line_num)
{
	stack_t *current_top;
	int size, result;

	size = 0;

	current_top = *stack;
	while (current_top)
	{
		current_top = current_top->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(env.file);
		free(env.content);
		custom_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current_top = *stack;
	if (current_top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(env.file);
		free(env.content);
		custom_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	result = current_top->next->n / current_top->n;
	current_top->next->n = result;
	*stack = current_top->next;
	free(current_top);
}
