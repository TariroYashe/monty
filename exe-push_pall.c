#include "monty.h"

/**
* is_integer - Check if a string is an integer
* @str: The string to check
*
* Return: 1 if the string is an integer, 0 otherwise
*/
int is_integer(const char *str)
{
int i;
if (str == NULL || *str == '\0')
return (0);

i = 0;
if (str[i] == '-' || str[i] == '+')
i++;

for (; str[i] != '\0'; i++)
{
if (!isdigit(str[i]))
return (0);
}

return (1);
}

/**
* push - Implementation of the push opcode
* @stack: A pointer to the stack
* @line_number: The current line number in the file
*/
void push(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;
char *arg;
/* Parse the line to get the integer argument */
arg = strtok(NULL, " \t\n");
if (arg == NULL || !is_integer(arg))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

/* Allocate memory for a new stack node */
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

/* Initialize the new node and push it onto the stack */
new_node->n = atoi(arg);
new_node->prev = NULL;
new_node->next = *stack;
if (*stack)
(*stack)->prev = new_node;
*stack = new_node;
}

/**
* pall - Implementation of the pall opcode
* @stack: A pointer to the stack
* @line_number: The current line number in the file
*/
void pall(stack_t **stack)
{
stack_t *current = *stack;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
* custom_getline - Custom implementation of getline
* @line: A pointer to the buffer where the line will be stored
* @len: A pointer to the size of the buffer
* @stream: The input stream to read from
*
* Description:
* - Reads a line from the input stream and stores it in the provided buffer.
* - Automatically resizes the buffer as needed to accommodate longer lines.
*
* Return:
* - The number of characters read, or -1 if an error occurs.
*/
int custom_getline(char **line, size_t *len, FILE *stream)
{
int ch;
size_t pos = 0;
if (!*line)
{
*line = malloc(128);
if (!*line)
return (-1);
*len = 128;
}
while ((ch = getc(stream)) != EOF && ch != '\n')
{
(*line)[pos++] = ch;
if (pos + 1 >= *len)
{
size_t new_size = *len * 2;
char *new_line = realloc(*line, new_size);
if (!new_line)
return (-1);
*line = new_line;
*len = new_size;
}
}
if (ch == EOF && pos == 0)
{
free(*line);
return (-1);
}
(*line)[pos] = '\0';
return (pos);
}

/**
* free_stack - Frees memory associated with the stack.
* @stack: A pointer to the top of the stack
*
* Description:
* - This function iterates through the stack and frees the memory
*   allocated for each node, ensuring there are no memory leaks.
*/
void free_stack(stack_t *stack)
{
while (stack)
{
stack_t *temp = stack;  /* Create a temporary pointer to the current node */
stack = stack->next;    /* Move to the next node */
free(temp);             /* Free the memory of the current node */
}
}
