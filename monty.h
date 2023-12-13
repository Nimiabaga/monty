#ifndef MONTY_H
#define MONTY_H

#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct MontyEnv - Environment for Monty interpreter
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag to change stack <-> queue
 * Description: Carries values through the program for Monty interpreter
 */
typedef struct MontyEnv
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} MontyEnv_t;

extern MontyEnv_t env;

/* Function prototypes */
void print_stack(stack_t **stack, unsigned int line_num);
void push_handler(stack_t **stack, unsigned int line_num);
void handle_push_error(unsigned int line_num, stack_t **stack);
void pint_handler(stack_t **stack, unsigned int line_num);
void pop_handler(stack_t **stack, unsigned int line_num);
void swap_handler(stack_t **stack, unsigned int line_num);
void add_handler(stack_t **stack, unsigned int line_num);
void nop_handler(stack_t **stack, unsigned int line_num);
void sub_handler(stack_t **stack, unsigned int line_num);
void div_handler(stack_t **stack, unsigned int line_num);
void mul_handler(stack_t **head, unsigned int line_num);
void mod_handler(stack_t **stack, unsigned int line_num);
int ex_opc(char *line, stack_t **stack, unsigned int line_num, FILE *m_file);
void pchar_handler(stack_t **stack, unsigned int line_num);
void pstr_handler(stack_t **stack, unsigned int line_num);
void rotl_handler(stack_t **stack, unsigned int line_num);
void rotr_handler(stack_t **stack, unsigned int line_num);
void custom_add_node(stack_t **stack, int value);
void custom_add_queue(stack_t **queue, int value);
void custom_free_stack(stack_t *stack);
void stack_handler(stack_t **stack, unsigned int line_num);
void queue_handler(stack_t **stack, unsigned int line_num);







#endif /* MONTY_H */