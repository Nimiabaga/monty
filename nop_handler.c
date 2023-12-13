#include "monty.h"
/**
 * nop_handler - Does nothing.
 * @stack: Pointer to the top of the stack.
 * @line_num: Line number in the file.
 */
void nop_handler(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
	/* Do nothing */
}

