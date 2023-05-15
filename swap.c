#include "header.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command in the Monty bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *top = *stack;
	stack_t *next = top->next;

	top->prev = next;
	top->next = next->next;
	next->prev = NULL;
	next->next = top;

	if (top->next)
		top->next->prev = top;

	*stack = next;
}
