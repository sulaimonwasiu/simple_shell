#include "main.h"

/**
 * custom_exit - couses normal process termination
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */
int custom_exit(char **args)
{
	/* exit with status */
	if (args[1])
	{
		return (atoi(args[1]));
	}
	/* exit success */
	else
	{
		return (0);
	}
}

/**
 * custom_env - function that prints enviroment variables
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int custom_env(char **args)
{
	int i = 0;
	(void)(**args);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}

/**
 * custom_cd - changes the working dir of the current shell executon env
 * @args: target directory
 *
 * Return: 1 one success, 0 otherwise.
 */
int custom_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in own_cd.c: changing dir\n");
		}
	}
	return (-1);
}
