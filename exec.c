#include "monty.h"

/**
 *execude_opcode - execution code for opcode
 *@stack: stack to be used
 *@opcode: code to look through
 *@line_number: line to look at
 *Return: once finished return
 */

void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{

		instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (int i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
