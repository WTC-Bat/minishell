#include "minishell.h"

/*
**	All code is WIP/An Idea
*/

/* UNECESSARY? */
static int	cd_back_count(char	**splits)
{
	int		cnt;

	cnt = 0;
	while (ft_strequ(splits[cnt], "..") == 1)
		cnt++;
	return (cnt);
}

char		*cd_navigate_back(t_env *tenv, char *arg)
{
	char	*splits;
	int		cnt;

	splits = ft_strsplit(arg, '/');
	cnt = 0;
	while (ft_strequ(splits[cnt], "..") == 1)
	{
		//sub as necessary
	}
	// ???
	// back_count = cd_back_count(splits);
	// then, we need to remove 'back_count' amount of directory from PWD
}
