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

#include "../libft/libft.h"
#include "../includes/minishell.h"

/* WIP */
// static char	*cd_go_back(char *arg)
// {
// 	char	**splits;
//
// 	splits = ft_strsplit(arg, '/');
// }

/* WIP [Still needs backward traversal and '-']*/
// static void cd_navigate_basic(t_env *tenv, char *arg)
// {
// 	char	*pwd;
// 	char	*new_pwd;
// 	int		chsuccess;
//
// 	pwd = get_env_val(tenv, "PWD");
// 	chsuccess = 0;
// 	if (ft_strequ(arg, "/") == 1)
// 		new_pwd = ft_strdup("/");
// 	else if (arg == NULL || (ft_strequ(arg, "~") == 1))	//?
// 		new_pwd = get_env_val(tenv, "HOME");
// 	else if (ft_strequ(arg, "-") == 1)
// 		new_pwd = get_env_val(tenv, "OLDPWD");
// 	chsuccess = chdir(new_pwd);
// 	if (chsuccess == 0)
// 	{
// 		replace_var(tenv, "OLDPWD", pwd);
// 		replace_var(tenv, "PWD", new_pwd);
// 	}
// 	else
// 		ft_putendl_fd("ERROR: Unable to change directory.", 2);
// 	// what if no if statements pass?
// 	ft_strdel(&pwd);
// 	ft_strdel(&new_pwd);
// }

/*
**	^
**	|
**	new
**
**	rework?
**	|
**	v
*/

static char	*get_path_back(char *arg, char *pwd)
{
	int		back_steps;
	char	*new_path;
	int		slash;

	back_steps = ft_splitcnt(arg, '/');
	new_path = ft_strdup(pwd);
	slash = 0;
	if (new_path[ft_strlen(new_path) - 1] == '/')
		new_path[ft_strlen(new_path) - 1] = '\0';
	while (back_steps > 0)
	{
		slash = ft_lindexof(new_path, '/');
		new_path = ft_strsub(new_path, 0, slash);
		back_steps--;
	}
	return (new_path);
}

static void	replacement(t_env *tenv, char *pwd, char *new_pwd)
{
	replace_var(tenv, "OLDPWD", pwd);
	replace_var(tenv, "PWD", new_pwd);
}

void		cd_navigate(char *arg, t_env *tenv)
{
	char	*new_pwd;
	char	*pwd;
	int		chsuccess;

	//
	if (ft_startswith(arg, "../") == 1)
	{
		// cd_go_back(arg);
		char * bckpth = cd_get_back_path(tenv, arg);
		ft_putendl(bckpth);
	}
	exit(0);
	//

	new_pwd = NULL;
	chsuccess = 0;
	pwd = get_env_val(tenv, "PWD");
	if (ft_strcmp(arg, "~") == 0)
		new_pwd = get_env_val(tenv, "HOME");
	else if (ft_strcmp(arg, "/") == 0)
		new_pwd = ft_strdup("/");
	else if (arg[0] == '.' && arg[1] == '.')
		new_pwd = get_path_back(arg, pwd);
	else
	{
		new_pwd = ft_strjoin(pwd, "/");
		new_pwd = ft_strjoin(new_pwd, arg);
	}
	chsuccess = chdir(new_pwd);
	if (chsuccess == 0)
		replacement(tenv, pwd, new_pwd);
	else
		ft_putendl("Error: Unable to change directory");
	free(pwd);
	free(new_pwd);
}
