#include "monty.h"

/**
 * pchar_handler - Prints the character at the top of the stack
 * @stack: Pointer to the stack
 * @line_num: Line number
 */
void pchar_handler(stack_t **stack, unsigned int line_num)
{
	stack_t *top;

	top = *stack;
	if (!top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		fclose(env.file);
		free(env.content);
		custom_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (top->n > 127 || top->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		fclose(env.file);
		free(env.content);
		custom_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}

