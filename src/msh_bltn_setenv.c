#include "../libft/libft.h"
#include "../includes/minishell.h"

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
		ft_putendl("Error: A variable with that name already exists");
		return (0);
	}
	return (1);
}

static void	add_new_var(t_env **tenv, char *var, char *val)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	ft_putendl("new malloc'd");//
	new->var = var;
	new->val = val;
	//new->next = NULL;
	while ((*tenv)->next != NULL)
		*tenv = (*tenv)->next;
	(*tenv)->next = new;
}

void	msh_setenv(t_env **tenv, char **args)
{
	if (args[1] == NULL)
		ft_putendl("Missing variable name");
	else if (args[2] == NULL)
		ft_putendl("Missing value for variable");
	else
		if (setenv_args_valid(*tenv, args) == 1)
			add_new_var(tenv, args[1], args[2]);
}
