#include "libft.h"
#include "minishell.h"

/* EXAMPLES! COULD BE MERGED */

void	cd_navigate_home(t_env *tenv)
{
	char	*home;
	char	*pwd;

	home = get_env_val(tenv, "HOME");
	pwd = get_env_val(tenv, "PWD");
	replace_var(tenv, "OLDPWD", pwd);
	replace_var(tenv, "PWD", home);
	ft_strdel(&pwd);
	chsuccess = chdir(home);
	ft_strdel(&home);
	if (chsuccess != 0)
		return (0);
	return (1);
}

void	cd_navigate_root()
{
	char	*pwd;

	pwd = get_env_val(tenv, "PWD");
	replace_var(tenv, "OLDPWD", pwd);
	replace_var(tenv, "PWD", "/");
	chsuccess = chdir("/");
	if (chsuccess != 0)
		return (0);
	return (1);
}


//////
