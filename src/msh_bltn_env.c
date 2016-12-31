/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_bltn_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 16:03:22 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/04 14:24:03 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env		*t_env_reverse(t_env *tenv)
{
	t_env	*new;
	t_env	*next;

	new = NULL;
	next = NULL;
	while (tenv != NULL)
	{
		next = tenv->next;
		tenv->next = new;
		new = tenv;
		tenv = next;
	}
	return (new);
}

char		*get_env_val(t_env *tenv, char *varname)
{
	char	*out;

	while (tenv != NULL)
	{
		if ((ft_strequ(tenv->var, varname)) == 1)
		{
			out = ft_strdup(tenv->val);
			return (out);
		}
		tenv = tenv->next;
	}
	return (NULL);
}

void		print_env(t_env *tenv)
{
	while (tenv != NULL)
	{
		ft_putstr(tenv->var);
		ft_putchar('=');
		ft_putendl(tenv->val);
		tenv = tenv->next;
	}
}

int			tenv_count(t_env *tenv)
{
	int		cnt;

	cnt = 0;
	while (tenv != NULL)
	{
		cnt++;
		tenv = tenv->next;
	}
	return (cnt);
}

t_env		*get_env(char **env)
{
	int		cnt;
	int		idx;
	int		lidx;
	t_env	*tenv;
	t_env	*root;

	cnt = 0;
	idx = -1;
	lidx = -1;
	root = NULL;
	while (env[cnt] != NULL)
	{
		tenv = (t_env *)malloc(sizeof(t_env));
		idx = ft_indexof(env[cnt], '=');
		lidx = ft_strlen(env[cnt]) - idx;
		tenv->var = ft_strsub(env[cnt], 0, idx);
		tenv->val = ft_strsub(env[cnt], idx + 1, lidx);
		tenv->next = root;
		root = tenv;
		cnt++;
	}
	return (t_env_reverse(root));
}
