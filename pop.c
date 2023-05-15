#include "header.h"

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command in the Monty bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
