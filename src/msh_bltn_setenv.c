/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_bltn_setenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 16:13:49 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/04 14:34:31 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	setenv_args_valid(t_env *tenv, char **args)
{
	if ((ft_strequ(args[0], "setenv")) == 0)
	{
		ft_putendl("Error: Unexpected error!");
		return (0);
	}
	if (strcnt(args) < 3)
	{
		ft_putendl("Error: Too few arguments for \"setenv\"");
		return (0);
	}
	if (strcnt(args) > 4)
	{
		ft_putendl("Error: Too many arguments for \"setenv\"");
		return (0);
	}
	if (get_env_val(tenv, args[1]) != NULL)
	{
		if (args[3] == NULL || ft_atoi(args[3]) == 0)
		{
			ft_putendl("Error: A variable with that name already exists");
			return (0);
		}
	}
	return (1);
}

void		replace_var(t_env *tenv, char *var, char *val)
{
	while (tenv != NULL)
	{
		if (ft_strcmp(tenv->var, var) == 0)	// ft_strequ?
		{
			ft_strdel(&(tenv)->val);
			tenv->val = ft_strdup(val);
			return ;
		}
		tenv = tenv->next;
	}
}

static int	var_exists(t_env *tenv, char *varname)
{
	while (tenv != NULL)
	{
		if (ft_strcmp(tenv->var, varname) == 0)
			return (1);
		tenv = tenv->next;
	}
	return (0);
}

static void	add_new_var(t_env **tenv, char *var, char *val)
{
	t_env	*new;

	if (var_exists(*tenv, var) == 1)
		replace_var(*tenv, var, val);
	else
	{
		new = (t_env *)malloc(sizeof(t_env));
		//new->var = var;
		//new->val = val;
		new->var = ft_strdup(var);
		new->val = ft_strdup(val);
		new->next = NULL;
		while ((*tenv)->next != NULL)
			*tenv = (*tenv)->next;
		(*tenv)->next = new;
	}
}

void		msh_setenv(t_env **tenv, char **args)
{
	if (args[1] == NULL)
		ft_putendl("Missing variable name");
	else if (args[2] == NULL)
		ft_putendl("Missing value for variable");
	else
	{
		if (setenv_args_valid(*tenv, args) == 1)
			add_new_var(tenv, args[1], args[2]);
	}
}
