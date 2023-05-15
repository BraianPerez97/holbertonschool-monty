#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command in the Monty bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *top = *stack;
	stack_t *next = top->next;

	next->n += top->n;
	*stack = next;
	next->prev = NULL;

	free(top);
}
