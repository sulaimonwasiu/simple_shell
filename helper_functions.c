#include "main.h"

/**
 * tokenizer- get token from command
 * @input: address of the command
 *
 * Return: pointer to a pointer
 */

char **tokenizer(char *input)
{
	int arg_count = 0;
	char *token = strtok(input, "  \t\n");
	char **args = (char **)malloc(sizeof(char *) * MAX_INPUT_LENGTH);

	if (args == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	return (args);
}
