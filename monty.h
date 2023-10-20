#ifndef MONTY_H
#define MONTY_H
#define MAX_LINE_LENGTH 1024
#define STACKSIZE 1024

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Define the instruction structure */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack);
int main(int argc, char *argv[]);
int is_integer(const char *str);
int custom_getline(char **line, size_t *len, FILE *stream);
void free_stack(stack_t *stack);


#endif
