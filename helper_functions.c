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

/**
 * command_exists- check if command exists
 * @command: the command
 *
 * Return: integer (boolean)
 */

int command_exists(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");

	while (token != NULL)
	{
		char command_path[MAX_COMMAND_LENGTH];

		snprintf(command_path, sizeof(command_path), "%s/%s", token, command);
		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (1);
		}

		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (0);
}
