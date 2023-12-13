#include "monty.h"

/**
 * stack_handler - Sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the stack
 * @line_num: Line number
 */
void stack_handler(stack_t **stack, unsigned int line_num)
{
	(void)line_num;
	(void)stack;
	env.lifi = 0;
}

/**
 * queue_handler - Sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the stack
 * @line_num: Line number
 */
void queue_handler(stack_t **stack, unsigned int line_num)
{
	(void)line_num;
	(void)stack;
	env.lifi = 1;
}

