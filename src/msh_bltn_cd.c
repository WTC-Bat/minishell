/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_bltn_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 16:12:15 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/02 14:20:06 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_error(void)
{
	ft_putendl_fd("ERROR: Unable to change directory.", 2);
}

static int	cd_is_basic(char *arg)
{
	if ((arg == NULL || ft_strequ(arg, "~") == 1 || ft_strequ(arg, "~/") == 1)
		|| (ft_strequ(arg, "-") == 1 || ft_strequ(arg, "-/") == 1)
		|| ft_strequ(arg, "/") == 1)
	{
		return (1);
	}
	return (0);
}

int			cd_args_valid(char *arg)
{
	struct stat	*st;
	int			valid;

	st = (struct stat *)malloc(sizeof(struct stat));
	valid = 0;
	stat(arg, st);
	if (S_ISDIR(st->st_mode) > 0)
		valid = 1;
	free(st);
	return (valid);
}

void		msh_cd(char **args, t_env *tenv)
{
	if (cd_is_basic(args[1]) == 1)
	{
		if (cd_navigate_basic(tenv, args[1]) == 0)
			cd_error();
	}
	else if (cd_args_valid(args[1]) == 1)
	{
		if (cd_navigate(args[1], tenv) == 0)
			cd_error();
	}
	else if (args[1][0] == '~')
	{
		if (cd_navigate_origin_home(tenv, args[1]) == 0)
			cd_error();
	}
	else
	{
		ft_putstr_fd("ERROR: No directory \"", 2);
		ft_putstr_fd(args[1], 2);
		ft_putendl_fd("\"", 2);
	}
}
