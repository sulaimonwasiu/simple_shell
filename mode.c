#include "main.h"

/**
 * interactive - shell in interactive mode
 *
 * Return: void
 */

void interactive(void)
{
	char *input;
	size_t input_length = 0;
	ssize_t nread;

	while (1)
	{

		write(STDOUT_FILENO, "($) ", 4);
		fflush(stdout);

		nread = getline(&input, &input_length, stdin);
		if (nread == EOF)
		{
			free(input);
			break;
		}

		input[_strlen(input) - 1] = '\0';
		execute_command(input);
	}
}

/**
 * non_interactive - shell in non_interactive mode
 *
 * Return: void
 */

void non_interactive(void)
{
	char *input;
	size_t input_length = 0;

	if (getline(&input, &input_length, stdin) != -1)
	{
		printf("I am in the non-interactive mode!!!!\n");
		input[_strlen(input) - 1] = '\0';
		execute_command(input);
	}
	free(input);
}
