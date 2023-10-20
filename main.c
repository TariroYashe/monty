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
* Return: 0 on success, EXIT_FAILURE on error.
*/
int main(int argc, char *argv[])
{
char *opcode;
stack_t *stack;
char *line = NULL;
size_t len = 0;
unsigned int line_number = 0;
FILE *file;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (custom_getline(&line, &len, file) != -1)
{
line_number++;
opcode = strtok(line, " \t\n");
if (opcode == NULL || opcode[0] == '#')
continue;  /*Skip empty lines and comments*/
if (strcmp(opcode, "push") == 0)
{
push(&stack, line_number);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(&stack);
}
else if (strcmp(opcode, "pint") == 0)
{
    pint(&stack, line_number);
}

/* Add more opcode cases here as needed*/
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}
fclose(file);
free(line);
return (0);
}
