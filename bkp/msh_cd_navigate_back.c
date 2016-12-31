#include "../includes/minishell.h"

#include "../libft/libft.h"

/*
**	All code is WIP/An Idea
*/

/* UNECESSARY? */
// static int	cd_back_count(char	**splits)
// {
// 	int		cnt;
//
// 	cnt = 0;
// 	while (ft_strequ(splits[cnt], "..") == 1)
// 		cnt++;
// 	return (cnt);
// }
//
// char		*cd_navigate_back(t_env *tenv, char *arg)
// {
// 	char	*splits;
// 	int		cnt;
//
// 	splits = ft_strsplit(arg, '/');
// 	cnt = 0;
// 	while (ft_strequ(splits[cnt], "..") == 1)
// 	{
// 		//sub as necessary
// 	}
// 	// ???
// 	// back_count = cd_back_count(splits);
// 	// then, we need to remove 'back_count' amount of directory from PWD
// }


///////////////////////////////////////////////////////////////////////////////

// static int	cd_back_only(char **splits)
// {
// 	int		cnt;
//
// 	cnt = 0;
// 	while (splits[cnt] != NULL)
// 	{
// 		if (ft_strequ(splits[cnt], "..") == 0)
// 			return (0);
// 		cnt++;
// 	}
// 	return (1);
// }

/* A PROTOTYPE - 2 [Unrelated to functions above] */

/* something is wrong. the < > part? */
char		*cd_get_back_path(t_env *tenv, char *arg)	// have PWD var instead of 'arg' ?
{
	char	**splits;
	char	*tmp;
	char	*tmp2;
	int		idx;
	int		cnt;

	/* or specify a char *arg parameter */
	char	*pwd;	// too many vars

	splits = ft_strsplit(arg, '/');
	tmp = NULL;
	tmp2 = NULL;
	idx = -1; // ?
	cnt = 0;
	pwd = get_env_val(tenv, "PWD");
	while (ft_strequ(splits[cnt], "..") == 1)
	{
		if (tmp == NULL)
		{
			tmp = ft_strdup(pwd);
			idx = ft_lindexof(tmp, '/');
			tmp2 = ft_strsub(tmp, 0, ((size_t)idx + 1));	// +1 ?
		}
		else
		{
			if (ft_strlen(tmp) > ft_strlen(tmp2))
			{
				ft_strdel(&tmp);
				idx = ft_lindexof(tmp2, '/');
				tmp = ft_strsub(tmp2, 0, ((size_t)idx + 1));
			}
			else
			{
				ft_strdel(&tmp2);
				idx = ft_lindexof(tmp, '/');
				tmp2 = ft_strsub(tmp, 0, ((size_t)idx + 1));
			}
		}
		cnt++;
	}
	ft_starfree(splits);
	if (ft_strlen(tmp) < ft_strlen(tmp2))
	{
		ft_strdel(&tmp2);
		return (tmp);
	}
	else
	{
		ft_strdel(&tmp);
		return (tmp2);
	}
}
