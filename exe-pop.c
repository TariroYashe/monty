#include "monty.h"

/**
* pop - Implementation of the pop opcode
* @stack: A pointer to the stack
* @line_number: The current line number in the file
*/
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *top;
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

top = *stack;
*stack = top->next;
if (*stack)
(*stack)->prev = NULL;

free(top);
}
