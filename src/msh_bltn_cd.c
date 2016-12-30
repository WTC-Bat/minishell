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

#include "../libft/libft.h"
#include "../includes/minishell.h"

/*
**	cd ../		-	go back one folder
**	cd /		-	go to root
**	cd			-	go to home folder
**	cd ~/path/	-	go to folder from home
**	cd /path/	-	go to folder from root
**	cd path/	-	go to folder from current position
**
**	HOME		=	~
**					~/
**					' '		[NULL]
**
**	ROOT		=	/
**
**	OLDPWD		=	-
**					-/
**
**	BACK		=	../
*/

/* ORIGINAL (in bkp) */

// int		cd_args_valid(char *args)
// {
// 	struct stat	st;
//
// 	stat(args, &st);
// 	if (S_ISDIR(st.st_mode) > 0 || ft_strcmp(args, "~") == 0)
// 		return (1);
// 	return (0);
// }
//
// void	msh_cd(char **args, t_env *tenv)
// {
// 	if (args[1] == NULL)
// 		cd_navigate("~", tenv);
// 	else
// 	{
// 		if (cd_args_valid(args[1]) == 1)
// 			cd_navigate(args[1], tenv);
// 		else
// 			ft_putendl("Error: Invalid path");
// 	}
// }



/* Attempt 2 */

/*
**	0	-	relative	(from current - 'path/') 	// ../ ?
**	1	-	absolute	(from root - '/')
**	2	-	(from home - '~/')
**	3	-	(from oldpwd - '-')
*/
/*WIP*/
/*???*/
// static int	cd_navigation_origin(char *arg)
// {
// 	if (ft_startswith(arg, "/") == 1)
// 		return (1);
// 	else if (ft_startswith(arg, "~") == 1 || ft_startswith(arg, "~/") == 1)
// 		return (2);
// 	else if (ft_startswith(arg, "-") == 1 || ft_startswith(arg, "-/") == 1)	//	|| ft_startswith(arg, "../")
// 		return (3);
// 	else
// 		return (0);
// }

static int	cd_navigate_basic(t_env *tenv, char *arg)
{
	char	*pwd;
	char	*new_pwd;
	int		chsuccess;
	int		success;

	pwd = get_env_val(tenv, "PWD");
	chsuccess = 0;
	success = 0;
	if (arg == NULL || ft_strequ(arg, "~") == 1 || ft_strequ(arg, "~/") == 1)
		new_pwd = get_env_val(tenv, "HOME");
	else if (ft_strequ(arg, "-") == 1 || ft_strequ(arg, "-/") == 1)
		new_pwd = get_env_val(tenv, "OLDPWD");
	else if (ft_strequ(arg, "/") == 1)
		new_pwd = ft_strdup("/");
	if ((chsuccess = chdir(new_pwd)) == 0)
	{
		replace_var(tenv, "PWD", new_pwd);
		replace_var(tenv, "OLDPWD", pwd);
		success = 1;
	}
	ft_strdel(&pwd);
	ft_strdel(&new_pwd);
	return (success);
}

static int	cd_args_valid(char *arg)
{
	struct stat	*st;
	int			valid;

	st = (struct stat *)malloc(sizeof(struct stat));
	valid = 0;
	stat(arg, st);
	if (S_ISDIR(st->st_mode) > 0 || ft_startswith(arg, "~/") == 1)
		valid = 1;
	free(st);
	return (valid);
}

static int	cd_is_basic(char *arg)
{
	if ((arg == NULL || ft_strequ(arg, "~") == 1 || ft_strequ(arg, "~/") == 1)
		|| ft_strequ(arg, "/") == 1 || ft_strequ(arg, "-") == 1)
	{
		return (1);
	}
	return (0);
}

void		msh_cd(char **args, t_env *tenv)
{
	if (cd_is_basic(args[1]) == 1)
	{
		if (cd_navigate_basic(tenv, args[1]) == 1)
			return ;
		else
			ft_putendl_fd("ERROR: Unable to change directory.", 2);
	}
	else if (cd_args_valid(args[1]) == 1)
	{
		ft_putendl("ARGS VALID");
		//WORK//
	}
	else
	{
		ft_putstr_fd("ERROR: No directory \"", 2);
		ft_putstr_fd(args[1], 2);
		ft_putendl_fd("\"", 2);
	}
}
