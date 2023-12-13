#include "monty.h"
int ex_opc(char *line, stack_t **stack, unsigned int line_num, FILE *m_file);
/**
 * ex_opc - Executes the opcode
 * @line: Line content
 * @stack: Stack head
 * @line_num: Line number
 * @m_file: Monty file
 * Return: 0 on success, 1 on failure
 */
int ex_opc(char *line, stack_t **stack, unsigned int line_num, FILE *m_file)
{
	instruction_t opcodes[] = {
		{"push", push_handler},
		{"pall", print_stack},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"nop", nop_handler},
		{"sub", sub_handler},
		{"div", div_handler},
		{"mul", mul_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"queue", queue_handler},
		{"stack", stack_handler},
		{NULL, NULL},
	};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(line, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	env.arg = strtok(NULL, " \n\t");

	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_num);
			return (0);
		}
		i++;
	}

	if (opcode && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		fclose(m_file);
		free(line);
		custom_free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}

