#include "main.h"

/**
 * execute_env_command- execute env
 *
 * Return: void
 */
void execute_env_command(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 * execute_command_from_path - execute from path
 *
 * @args: arguments
 * @path: path
 *
 * Return: void
 */

void execute_command_from_path(char **args, char *path)
{
	char full_path[MAX_INPUT_LENGTH];
	int path_len = _strlen(path);
	int cmd_len = _strlen(args[0]);

	if (path_len + cmd_len + 2 < MAX_INPUT_LENGTH)
	{
		_strcpy(full_path, path);
		full_path[path_len] = '/';
		_strcpy(full_path + path_len + 1, args[0]);
	}
	else
	{
		write(STDERR_FILENO, "Path too long\n", 14);
		free(args);
		exit(EXIT_FAILURE);
	}

	if (access(full_path, X_OK) == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("/shell");
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * execute_child_process - run child process
 * @args: command
 *
 * Return: void
 */

void execute_child_process(char **args)
{
	if (access(args[0], X_OK) == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("/shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		char *path_env = getenv("PATH");
		char *path = strtok(path_env, ":");
		char *not_found_message = "./hsh";
		char *command_name = args[0];
		char *error_message = ": not found\n";

		while (path != NULL)
		{
			execute_command_from_path(args, path);
			path = strtok(NULL, ":");
		}
		write(STDERR_FILENO, not_found_message, _strlen(not_found_message));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, command_name, _strlen(command_name));
		write(STDERR_FILENO, error_message, _strlen(error_message));
		free(args);
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_regular_command - process
 * @args: commands
 *
 * Return: void
 */

void execute_regular_command(char **args)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		free(args);
		return;
	}
	else if (pid == 0)
	{
		execute_child_process(args);
	}
	else
	{
		int status;

		wait(&status);
	}
}

/**
 * execute_command - run command
 * @command: command line argument
 *
 * Return: void
 */

void execute_command(char *command)
{
	char **args = tokenizer(command);

	if (strlen(command) == 0 || strspn(command, " \t\n") == strlen(command))
		return;
	/*Execute built-in commands*/
	if (_strcmp(args[0], "env") == 0)
		execute_env_command();

	if (_strcmp(args[0], "exit") != 0)
		execute_regular_command(args);
	else
	{
		int status;

		status = custom_exit(args);
		free(args);
		exit(status);
	}
	free(args);
}
