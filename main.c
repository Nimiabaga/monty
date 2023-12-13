#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]);
MontyEnv_t env;

/**
 * main - interpreter
 * @argc: argument numbers
 * @argv: file location
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *line;
	FILE *m_file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	m_file = fopen(argv[1], "r");
	env.file = m_file;
	if (!m_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line = NULL;
		read_line = getline(&line, &size, m_file);
		env.content = line;
		line_num++;
		if (read_line > 0)
		{
			ex_opc(line, &stack, line_num, m_file);
		}
		free(line);
	}
	custom_free_stack(stack);
	fclose(m_file);
	return (0);
}
