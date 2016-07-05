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

/*
static void	remove_var(t_env **tenv, char *varname)
{
	//t_env	*tmp;

	//while (*tenv != NULL)
	//{
	//	if ((ft_strequ((*tenv)->var, varname)) == 1)
	//	{
	//		ft_putendl("IS EQU");
	//		(*tenv)->var = (*tenv)->next->var;
	//		(*tenv)->val = (*tenv)->next->val;
	//		tmp = (*tenv)->next;
	//		(*tenv)->next = (*tenv)->next->next;
	//		free(tmp);
	//	}
	//	*tenv = (*tenv)->next;
	//}

	/////////////////////////

	//while (*tenv != NULL)
	//{
	//	if ((ft_strequ((*tenv)->var, varname)) == 1)
	//	{
	//		(*tenv)->var = NULL;
	//		(*tenv)->val = NULL;
	//		free(*tenv);
	//	}
	//	*tenv = (*tenv)->next;
	//}

	//////////////////////

	//int		found;
	//int		end;

	//found = 0;
	//while ((*tenv)->next != NULL)
	//{
	//	if ((ft_strequ((*tenv)->var, varname)) == 1)
	//		found = 1;

	//	ft_putendl((*tenv)->var);
	//	ft_putendl(varname);
	//	if (found == 1)
	//	{
	//		(*tenv)->var = (*tenv)->next->var;
	//		(*tenv)->val = (*tenv)->next->val;
	//	}
	//	*tenv = (*tenv)->next;
	//}
}
*/

/*
static t_env	*remove_var(t_env *tenv, char *varname)
{
	t_env	*new_env;

	while (tenv != NULL)
	{
		new_env = (t_env *)malloc(sizeof(t_env));
		if ((ft_strequ(tenv->var, varname)) == 0)
		{
			new_env = tenv;
			new_env = new_env->next;
		}
		tenv = tenv->next;
	}
	free(tenv);
	return (new_env);
}
*/

//The two remove_var functions are supplementary and must be dissected
//Iterative
void	remove_var(t_env **tenv, char *varname)
{
	t_env	*tmp;
	t_env	*prev;

	prev = NULL;
	tmp = *tenv;
	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		if ((ft_strequ((*tenv)->var, varname)) == 1)
		{
			if (prev == NULL)
				*tenv = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp);
			//break;
		}
	}
}

/*
//Recursive
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
*/

void	msh_unsetenv(t_env **tenv, char **args)
{
	if (unsetenv_args_valid(*tenv, args) == 1)
		//remove_var(tenv, args[1]);
		ft_putendl("REMOVE_VAR");
}
