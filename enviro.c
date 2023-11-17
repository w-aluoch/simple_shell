#include "shell.h"

/**
 * _env - prints the current environment
 * @info: Contains potential arguments,
 *         that keeps constant function prototype.
 * Return: Always 0
 */
int _env(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
 * _collectenv - collets the value of an environment variable
 * @info: Contains potential arguments,
 * that keeps constant function prottotype
 * @name: environment variable name
 *
 * Return: the value
 */
char *_collectenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *g;

while (node)
{
g = starts_with(node->str, name);
if (g && *g)
return (g);
node = node->next;
}
return (NULL);
}

/**
 * _putenv - Actuate a new environment variable,
 *             or modify an existing one
 * @info: Contains potential arguments,
 *       that keeps constant function prototype.
 * Return: 0 on success, -1 on failure
 */
int _putenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguments\n");
return -1;
}

if (_setenv(info, info->argv[1], info->argv[2]) == 0)
return 0;

return -1;
}

/**
 * _unsetenv - Removes an environment variable
 * @info: Contains potential arguments,
 *      that keeps constant function prototype.
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(info_t *info)
{
int u;

if (info->argc == 1)
{
_eputs("Too few arguments.\n");
return -1;


for (u = 1; u < info->argc; u++)
{
if (_unsetenv(info, info->argv[u]) == -1)
return -1;
}

return 0;
}

/**
 * occupy_env_list - occupies environment linked list
 * @info: Contains potential arguments,
 *         that keeps constant function prototype.
 * Return: 0 on success, -1 on failure
 */
int occupy_env_list(info_t *info)
{
list_t *node = NULL;
size_t c;

for (c = 0; environ[c]; c++)
{
if (add_node_end(&node, environ[c], 0) == -1)
return -1;
}

info->env = node;
return 0;
}
