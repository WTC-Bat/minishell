#include "../libft/libft.h"
#include "../includes/minishell.h"

/*
**	/		-	move to top of boot volume
**	..		-	parent folder
**	../..	-	parent of parent (grand parent)
**	~		-	home directory
**	-OR JUST-
**	cd		-	home directory
*/

static char	*get_path_back(char *arg, char *pwd)
{
	int		back_steps;
	char	*new_path;
	int		slash;

	back_steps = ft_splitcnt(arg, '/');
	new_path = ft_strdup(pwd);
	slash = 0;
	if (new_path[ft_strlen(new_path) - 1] == '/')
		new_path[ft_strlen(new_path) - 1] = '\0';
	while (back_steps > 0)
	{
		slash = ft_lindexof(new_path, '/');
		new_path = ft_strsub(new_path, 0, slash);
		back_steps--;
	}
	return (new_path);
}

void	cd_navigate(char *arg, t_env *tenv)
{
	char	*new_pwd;
	char	*pwd;

	new_pwd = NULL;
	pwd = NULL;
	pwd = get_env_val(tenv, "PWD");
	if (ft_strcmp(arg, "~") == 0)
		new_pwd = get_env_val(tenv, "HOME");
	else if (ft_strcmp(arg, "/") == 0)
		new_pwd = ft_strdup("/");
	else if (arg[0] == '.' && arg[1] == '.')
	{
		new_pwd = get_path_back(arg, pwd);
	}
	else
	{
		new_pwd	= ft_strjoin(pwd, "/");
		new_pwd = ft_strjoin(new_pwd, arg);
	}
	replace_var(&tenv, "OLDPWD", pwd);
	replace_var(&tenv, "PWD", new_pwd);
	chdir(new_pwd);
	free(pwd);
	free(new_pwd);
}
