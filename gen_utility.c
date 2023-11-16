#include "shell.h"

/**
 * interactive - return true if shell is interactive mode
 * @info: struct addresses
 * @readfd: member
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info, int readfd)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @j: the character to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char j, char *delim)
{
	while (*delim)
		if (*delim++ == j)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@j: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int j)
{
	if ((j >= 'a' && j <= 'z') || (j >= 'A' && j <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts  string to an integer
 *@m: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *m)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  m[i] != '\0' && flag != 2; i++)
	{
		if (m[i] == '-')
			sign *= -1;

		if (m[i] >= '0' && m[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (m[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
