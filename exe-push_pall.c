#include "monty.h"

/**
* create_stack - Create a new stack.
* Return: A pointer to the newly created stack.
*/
stack_t *create_stack(void)
{
stack_t *stack = NULL;
return (stack);
}

/**
* push - Push a new element onto the stack.
* @stack: A pointer to the stack.
* @line_number: The current line number.
* @arg: The argument to push.
*/
void push(stack_t **stack, unsigned int line_number, char *arg)
{
int value;
stack_t *new_node;
if (arg == NULL)
{
fprintf(stderr, "L%d: missing argument for push\n", line_number);
exit(EXIT_FAILURE);
}
value = strtol(arg, NULL, 10);
if (value == 0 && *arg != '0')
{
fprintf(stderr, "L%d: invalid argument for push: %s\n", line_number, arg);
exit(EXIT_FAILURE);
}

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;
if (*stack)
(*stack)->prev = new_node;
*stack = new_node;
}

/**
* pall - Print all the elements of the stack.
* @stack: A pointer to the stack.
* @line_number: The current line number.
* @arg: An argument (not used in this function).
*/
void pall(stack_t **stack, char *arg)
{
stack_t *current = *stack;
(void)arg; // Unused parameter

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
* free_stack - Free all memory associated with the stack.
* @stack: A pointer to the stack to free.
*/
void free_stack(stack_t *stack)
{
while (stack)
{
stack_t *temp = stack;
stack = stack->next;
free(temp);
}
}

/**
* execute_instruction - Execute a Monty bytecode instruction.
* @instruction: The instruction to execute.
* @stack: A pointer to the stack.
* @line_number: The current line number.
* @arg: An argument for the opcode (push value).
*/
void execute_instruction(const char *instruction,
stack_t **stack, unsigned int line_number, char *arg)
{
if (strcmp(instruction, "push") == 0)
{
push(stack, line_number, arg);
}
else if (strcmp(instruction, "pall") == 0)
{
pall(stack, line_number, arg);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
exit(EXIT_FAILURE);
}
}

/**
* main - The entry point of the Monty ByteCode interpreter.
* @argc: The number of command-line arguments.
* @argv: An array of command-line argument strings.
* Return: (EXIT_SUCCESS) on success, (EXIT_FAILURE) on failure.
*/
int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

FILE *file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

char line[100]; /* Adjust the buffer size as needed */
unsigned int line_number = 0;
stack_t *stack = create_stack();

while (fgets(line, sizeof(line), file) != NULL)
{
line_number++;
char *token = strtok(line, " \t\n");
char *arg = strtok(NULL, " \t\n"); /* Get the argument token */

if (token != NULL)
{
execute_instruction(token, &stack, line_number, arg);
}
}

fclose(file);
free_stack(stack);
return (EXIT_SUCCESS);
}
