#include "main.h"
/**
 * main - entry to the program
 * @argc: argument count
 * @argv: arguments
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	if (isatty(STDIN_FILENO))
	{
		interactive();
	}
	else
	{
		non_interactive();
	}
	return (0);
}
