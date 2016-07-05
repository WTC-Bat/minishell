#include "../libft/libft.h"
#include "../includes/minishell.h"

int		unsetenv_args_valid(t_env *tenv, char **args)
{
	if ((ft_strequ(args[0], "unsetenv")) == 0)
	{
		ft_putendl("Error: Unexpected error!");
		return (0);
	}
	if (strcnt(args) < 2)
	{
		ft_putendl("Error: Too few arguments for \"unsetenv\"");
		return (0);
	}
	if (strcnt(args) > 2)
	{
		ft_putendl("Error: Too many arguments for \"unsetenv\"");
		return (0);
	}
	if (get_env_val(tenv, args[1]) == NULL)
	{
		ft_putendl("Error: Variable not found");
		return (0);
	}
	return (1);
}

//The two remove_var functions are supplementary and must be dissected
//Not Working
//Iterative
/*
void	remove_var(t_env **tenv, char *varname)
{
	t_env	*tmp;
	t_env	*prev;

	prev = NULL;
	tmp = *tenv;
	while (tmp != NULL)
	{
		tmp = *tenv;
		prev = tmp;
		tmp = tmp->next;
		if ((ft_strequ((*tenv)->var, varname)) == 1)
		{
			if (prev == NULL)
				*tenv = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp);
			break;
		}
	}
}
*/

//Recursive
//Works
t_env	*remove_var(t_env *tenv, char *varname)
{
	t_env	*tmp;

	if ((ft_strequ(tenv->var, varname)) == 1)
	{
		tmp = tenv->next;
		free(tenv);
		return(tmp);
	}
	tenv->next = remove_var(tenv->next, varname);
	return (tenv);
}

void	msh_unsetenv(t_env **tenv, char **args)
{
	if (unsetenv_args_valid(*tenv, args) == 1)
		remove_var(tenv, args[1]);
		//ft_putendl("REMOVE_VAR");
}
