/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_handle_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 07:37:20 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/01/11 07:37:21 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		msh_handle_input(char **args, t_env *tenv)
{
	// ft_putendl("HANDLE_INPUT");
	if ((ft_strcmp(args[0], "env")) == 0)
		print_env(tenv);
	else if ((ft_strcmp(args[0], "echo")) == 0)
		msh_echo(tenv, args);
	else if ((ft_strcmp(args[0], "setenv")) == 0)
		msh_setenv(&tenv, args);
	else if ((ft_strcmp(args[0], "unsetenv")) == 0)
		msh_unsetenv(&tenv, args);
	else if (ft_strcmp(args[0], "cd") == 0)
		msh_cd(args, tenv);
	else if ((ft_strcmp(args[0], "exit")) == 0)
		return (1);
	else
	{
		if (msh_exec(args, tenv) == -1)
		{
			ft_putstr(args[0]);
			ft_putendl(": Unknown command");
		}
	}
	return (0);
}
