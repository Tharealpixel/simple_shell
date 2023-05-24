#include "main.h"

/**
 *_menver -print function the current environment
 * @info: structure potential arguments. used to main
 *       constant function prototype.
 * Return: Always 0
 */
int _menver(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenver -gets the value of an environ variable
 * @info: strcture potentail argument; use main
 *           constant function prototype.
 * @nm: enver variable name
 *
 * Return: the value
 */
char *_getenver(info_t, const char *nm)
{
	list_t *node = info->enver;
	char *p;

	while (node)
	{
		p = start_with(node->str, nm);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
/**
 * _msetenver -Initialize a new environment variable,
 *	       or a exiting one
 * @info: structure cotain potential argum. to main
 *              constant function prototype.
 * Return: Always 0
 */
int _msetenver(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("number of argument\n");
		return (1);
	}
	if (_setenver(info, info->argv[1], info->argv[2]))
		return (0);
	return (0);
	return (1);
}
/**
 * _insetenver -Remove function
 * @info: struct containing potential arguments. used to main
 *                constant function pototype.
 * Return: Always 0
 */
int _insetever(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("few arguments.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_insetenver(info, info->argv[i]);

	return (0);
}
/**
 * _enver_list -evern linked list
 * @info: struct potential arguments. used to main
 *              constant function prototype
 * Return: Always 0
 */
int _enver_list(info_t *int)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; enveron[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->enver = node;
	return (0);
}
