#include "monty.h"

/**
 * monty_nop - Does nothing; opcode 'nop' for Monty.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - Prints the character at the top of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error_code(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error_code(pchar_error(line_number,
									 "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}
