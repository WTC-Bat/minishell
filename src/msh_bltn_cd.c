/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_bltn_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 16:12:15 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/07/26 14:42:35 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/minishell.h"

int		cd_args_valid(char *args)
{
	struct stat	st;

	stat(args, &st);
	if (S_ISDIR(st.st_mode) > 0 || ft_strcmp(args, "~") == 0)
		return (1);
	return (0);
}

void	msh_cd(char **args, t_env *tenv)
{
	if (args[1] == NULL)
		cd_navigate("~", tenv);
	else
	{
		if (cd_args_valid(args[1]) == 1)
			cd_navigate(args[1], tenv);
		else
			ft_putendl("Error: Invalid path");
	}
}
