#include "../libft/libft.h"
#include "../includes/minishell.h"

int		cd_args_valid(char *args)
{
	struct stat	st;

	stat(args, &st);
	if (S_ISDIR(st.st_mode) > 0)
		return (1);
	return (0);
}

void	msh_cd(char	**args, t_env *tenv)
{
	if (args[1] == NULL)
	{
		//replace_var(&tenv, "OLDPWD", get_env_val(tenv, "PWD"));
		//replace_vat(&tenv, "PWD", get_env_val(tenv, "HOME"));
		cd_navigate("~", tenv);
	}
	else
	{
		if (cd_args_valid(args[1]) == 1)
			cd_navigate(args[1], tenv);
		else
			ft_putendl("Error: Invalid path");

	}
}
