#include "monty.h"

/**
 * push_handler - Function to handle the push opcode
 * @stack: Pointer to the stack
 * @line_num: Line number in the file
 */
void push_handler(stack_t **stack, unsigned int line_num)
{
	size_t index;
	int value;

	if (!env.arg || !*env.arg)
	{
		if (*stack == NULL)
		{
			/* Stack is empty, nothing to push */
			return;
		}

		handle_push_error(line_num, stack);
	}

	for (index = (env.arg[0] == '-'); env.arg[index]; ++index)
	{
		if (!isdigit(env.arg[index]))
		{
			handle_push_error(line_num, stack);
		}
	}

	value = atoi(env.arg);

	if (env.lifi == 0)
	{
		custom_add_node(stack, value);
	}
	else
	{
		custom_add_queue(stack, value);
	}
}



/**
 * handle_push_error - Helper function to handle errors during push operation
 * @line_num: Line number in the file
 * @stack: Pointer to the stack
 */
void handle_push_error(unsigned int line_num, stack_t **stack)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_num);
	fclose(env.file);
	free(env.content);

	if (*stack != NULL)
	{
		custom_free_stack(*stack);
	}

	exit(EXIT_FAILURE);
}
