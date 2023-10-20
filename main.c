#include "monty.h"

/**
* main - Monty ByteCodes interpreter main function
* @argc: The number of command-line arguments
* @argv: An array of command-line arguments
*
* Description:
* - Checks command-line arguments and opens the Monty ByteCode file.
* - Reads and interprets the file line by line, executing valid opcodes.
*
* Return:
* - 0 on success, EXIT_FAILURE on error.
*/
int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

FILE *file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}

char *line = NULL;
size_t len = 0;
unsigned int line_number = 0;
stack_t *stack = NULL;
char *opcode;

while (custom_getline(&line, &len, file) != -1)
{
line_number++;
opcode = strtok(line, " \t\n");
if (!opcode || opcode[0] == '#')
{
continue;  /*Skip empty lines and comments*/
}

if (strcmp(opcode, "push") == 0)
{
push(&stack, line_number);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(&stack);
}
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
free(line);
fclose(file);
free_stack(stack);
return (EXIT_FAILURE);
}
}

free(line);
fclose(file);
free_stack(stack);

return (EXIT_SUCCESS);
}

