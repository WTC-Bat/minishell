/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd_navigate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 15:52:40 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/04 14:39:19 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*cd_get_path_from_home(t_env *tenv, char *arg)
{
	char	*home;
	char	*sub;
	char	*path_from_home;
	char	*tmp;
	int		substart;

	home = get_env_val(tenv, "HOME");
	tmp = ft_strjoin(home, "/");
	substart = 1;
	if (arg[1] == '/')
		substart = 2;
	sub = ft_strsub(arg, substart, ft_strlen(arg) - substart);
	path_from_home = ft_strjoin(tmp, sub);
	ft_strdel(&home);
	ft_strdel(&tmp);
	ft_strdel(&sub);
	return (path_from_home);
}

int			cd_navigate_origin_home(t_env *tenv, char *arg)
{
	char	*path;
	char	*pwd;
	int		success;

	path = cd_get_path_from_home(tenv, arg);
	pwd = get_env_val(tenv, "PWD");
	success = 0;
	if (cd_args_valid(path) == 1)
	{
		if (chdir(path) == 0)
		{
			replace_var(tenv, "PWD", path);
			replace_var(tenv, "OLDPWD", pwd);
			success = 1;
		}
	}
	ft_strdel(&path);
	ft_strdel(&pwd);
	return (success);
}

int			cd_navigate_basic(t_env *tenv, char *arg)
{
	char	*pwd;
	char	*new_pwd;
	int		success;

	pwd = get_env_val(tenv, "PWD");
	success = 0;
	if (arg == NULL || ft_strequ(arg, "~") == 1 || ft_strequ(arg, "~/") == 1)
		new_pwd = get_env_val(tenv, "HOME");
	else if (ft_strequ(arg, "-") == 1 || ft_strequ(arg, "-/") == 1)
		new_pwd = get_env_val(tenv, "OLDPWD");
	else if (ft_strequ(arg, "/") == 1)
		new_pwd = ft_strdup("/");
	if (chdir(new_pwd) == 0)
	{
		replace_var(tenv, "PWD", new_pwd);
		replace_var(tenv, "OLDPWD", pwd);
		success = 1;
	}
	ft_strdel(&pwd);
	ft_strdel(&new_pwd);
	return (success);
}

int			cd_navigate(char *arg, t_env *tenv)
{
	char	*pwd;
	char	*new_pwd;
	int		success;

	success = 0;
	if (chdir(arg) == 0)
	{
		pwd = get_env_val(tenv, "PWD");
		new_pwd = (char *)malloc(sizeof(char) * 1024);
		new_pwd = getcwd(new_pwd, 1024);
		replace_var(tenv, "PWD", new_pwd);
		replace_var(tenv, "OLDPWD", pwd);
		ft_strdel(&pwd);
		ft_strdel(&new_pwd);
		success = 1;
	}
	return (success);
}
