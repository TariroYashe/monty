#include "monty.h"

/**
* push - Pushes an element onto the stack
* @stack: Double pointer to the head of the stack
* @value: The value to be pushed onto the stack
* Description: This function creates a new node with the given value and adds
* it to the top of the stack.
*/
void push(stack_t **stack, int value)
{
/*Allocate memory for a new node*/
stack_t *new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
/*Initialize the new node*/
new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;
/*Update the previous node's reference*/
if (*stack)
(*stack)->prev = new_node;
/*Update the stack pointer to the new node*/
*stack = new_node;
}

/**
* pall - Prints all values on the stack
* @stack: Pointer to the head of the stack
*
* Description: This function prints all the integer values on the stack
* starting from the top of the stack and moving downwards.
*/
void pall(stack_t *stack)
{
/*Traverse the stack and print values*/
while (stack != NULL)
{
printf("%d\n", stack->n);
stack = stack->next;
}
}

/**
* main - entry point
* @argc: argument count
* @argv: argument vector
* Return: 0
*/
int main(int argc, char *argv[])
{
stack_t *stack = NULL;
char line[MAX_LINE_LENGTH], *opcode;
FILE *file;
int line_number = 0, value;
{
if (argc < 2) {
printf("Usage: %s <argument>\n", argv[0]);
return (1);/*Exit with an error status code*/
}
printf("Program name: %s\n", argv[0]);
printf("First argument: %s\n", argv[1]);

return (0);
}
while (fgets(line, sizeof(line),file) != NULL)
{
line_number++;
/*Tokenize the input line to extract the opcode*/
opcode = strtok(line, " \t\n");
if (opcode == NULL || *opcode == '#')
continue; /*Skip empty lines and comments*/
if (strcmp(opcode, "push") == 0)
{
/*Extract and validate the argument*/
char *arg = strtok(NULL, " \t\n");
if (arg == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
value = atoi(arg);
if (value == 0 && arg[0] != '0')
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
/*Call the push function to add the value to the stack*/
push(&stack, value);
}
else if (strcmp(opcode, "pall") == 0)
{
/*Call the pall function to print stack values*/
pall(stack);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}
/*Clean up and close the file*/
fclose(file);
/*Free allocated memory, if any*/
return (0);
}
