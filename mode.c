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

		/*write(STDOUT_FILENO, "($) ", 4);*/
		/*fflush(stdout);*/
		printf("#cisfun$ ");

		nread = getline(&input, &input_length, stdin);
		if (nread == EOF)
		{
			break;
		}

		input[_strlen(input) - 1] = '\0';
		execute_command(input);
	}

	free(input);
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

	while (getline(&input, &input_length, stdin) != -1)
	{
		input[_strlen(input) - 1] = '\0';
		execute_command(input);
	}

	free(input);
}
