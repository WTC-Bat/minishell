#include "../libft/libft.h"
#include "../includes/minishell.h"

extern char		**environ;

t_env	*t_env_reverse(t_env *tenv)
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

char	*get_env_val(t_env *tenv, char *varname)
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

void	print_env(t_env *tenv)
{
	while (tenv != NULL)
	{
		ft_putstr(tenv->var);
		ft_putchar('=');
		ft_putendl(tenv->val);
		tenv = tenv->next;
	}
}

int		tenv_count(t_env *tenv)
{
	int		cnt;

	cnt = 0;
	while (tenv != NULL)
	{
		cnt++;
		tenv = tenv->next;
	}
	return (cnt + 1);
}

t_env			*get_env()
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
	while (environ[cnt] != NULL)
	{
		tenv = (t_env *)malloc(sizeof(t_env));
		idx = ft_indexof(environ[cnt], '=');
		lidx = ft_strlen(environ[cnt]) - idx;
		tenv->var = ft_strsub(environ[cnt], 0, idx);
		tenv->val = ft_strsub(environ[cnt], idx + 1, lidx);
		tenv->next = root;
		root = tenv;
		cnt++;
	}
	return (t_env_reverse(root));
}
