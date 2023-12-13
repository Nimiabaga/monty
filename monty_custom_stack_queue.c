

#include "monty.h"

/**
 * custom_add_node - Adds a new node to the stack
 * @stack: Pointer to the head of the stack
 * @value: Value to be added
 */
void custom_add_node(stack_t **stack, int value)
{
	stack_t *new_node, *current;

	current = *stack;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (current)
	{
		current->prev = new_node;
	}

	*stack = new_node;
}

/**
 * custom_add_queue - Adds a new node to the queue
 * @queue: Pointer to the head of the queue
 * @value: Value to be added
 */
void custom_add_queue(stack_t **queue, int value)
{
	stack_t *new_node, *current;

	current = *queue;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = NULL;

	if (current)
	{
		while (current->next)
		{
			current = current->next;
		}
	}

	if (!current)
	{
		*queue = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current->next = new_node;
		new_node->prev = current;
	}
}

