#include "monty.h"

/**
 * mod_handler - Computes the rest of the
 * division of the second top element
 * by the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_num: Line number in the file.
 */
void mod_handler(stack_t **stack, unsigned int line_num)
{
	stack_t *current_top;
	int stack_size, result;

	current_top = *stack;

	/* Count the number of nodes in the stack */
	for (stack_size = 0; current_top != NULL; stack_size++)
		current_top = current_top->next;

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
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

	result = current_top->next->n % current_top->n;

	/* Update the stack */
	current_top->next->n = result;
	*stack = current_top->next;

	/* Remove the top element from the stack */
	free(current_top);
}

