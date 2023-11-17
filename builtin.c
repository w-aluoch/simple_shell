#include "shell.h"

/**
 * _exit - exits the shell
 * @info: Contains potential arguments,
 *         that keeps constant function prototype.
 *  Return: (0) if info.argv[0] != "exit"
 */
int _exit(info_t *info)
{
int checker;

if (info->argv[1])  /* If there is an exit arguement */
{
checker = _erratoi(info->argv[1]);
if (checker == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}

/**
 * _cd - changes the current directory of the process
 * @info: Contains potential arguments,
 *        that keeps constant function prototype.
 *  Return: Always 0
 */
int _cd(info_t *info)
{
char *c, *drt, buffer[1024];
int changedrt_r;

c = getcwd(buffer, 1024);
if (!c)
_puts("Error: Unable to retrieve current working directory\n");
if (!info->argv[1])
{
drt = _getenv(info, "HOME=");
if (!drt)
changedrt_r = /* TODO: what should this be? */
changedrt((drt = _getenv(info, "PWD=")) ? drt : "/");
else
changedrt_r = changedrt(drt);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
changedrt_r = /* TODO: what should this be? */
changedrt((drt = _getenv(info, "OLDPWD=")) ? drt : "/");
}
else
changedrt_r = changedrt(info->argv[1]);
if (changedrt_r == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
 * _help - changes the current directory of the process
 * @info: Contains potential arguments,
 *        that keeps constant function prototype.
 *  Return: Always 0
 */
int _help(info_t *info)
{
char **arg_array;

arg_array = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*arg_array); /* temp att_unused workaround */
return (0);
}
