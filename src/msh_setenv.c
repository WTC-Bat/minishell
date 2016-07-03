void	msh_setenv(char *var, char *val)
{
	t_env	tenv;// *tenv;

	if (var == NULL)
		ft_putendl("Missing variable name");
	else if (val == NULL)
		ft_putendl("Missing value for variable");
	else
	{
		tenv = (t_env *)malloc(sizeof(t_env));
		t_env.variable = var;
		//t_env->variable = var;
		t_env.value = val;
		//t_env->value = val;
		//add to list
	}
}
