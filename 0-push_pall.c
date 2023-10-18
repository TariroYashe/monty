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
char line[MAX_LINE_LENGTH];
FILE *file;
int line_number = 0;
if (argc != 2)
{
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
return (EXIT_FAILURE);
}
file = fopen(argv[1], "r"); /*Open the file for reading*/
if (file == NULL)
{
fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
return(EXIT_FAILURE);
}
while (fgets(line, sizeof(line), file) != NULL)/* Use the 'file' variable, not uninitialized 'file'*/
{
line_number++;
/*The rest of your code remains the same.*/
}
/* Clean up and close the file*/
fclose(file);
/* Free allocated memory, if any*/
return (0);
}
