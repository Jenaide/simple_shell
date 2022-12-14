#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @info: struct address
 * Return: 1 if in interactive mode, o if otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <=2);
}

/**
 * is_delim - checks if char is a delimeter
 * @c: character to be checked
 * @delim: delimeter string
 * Return: 1 if true else 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpa - checks for the alphabetic chars
 * @c: characcter input
 * Return: 1 if c is alpha else 0 if otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi - converts a string into an integer
 * @s: string to be converted
 * Return: 0 if there is no number in string else convert number
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = result;
	else
		output = result;

	return (output);
}
