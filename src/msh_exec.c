/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 14:15:33 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/07/08 14:32:50 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_fpath(char *path, char *pname)
{
	char	*tmp;
	char	*fpath;

	tmp = ft_strjoin(path, "/");
	fpath = ft_strjoin(tmp, pname);
	if (access(fpath, F_OK) == 0 && access(fpath, X_OK) == 0)
	{
		ft_strdel(&tmp);
		return (fpath);
	}
	ft_strdel(&tmp);
	ft_strdel(&fpath);
	return (NULL);
}

static char	*get_prog_path(t_env *tenv, char *pname)
{
	char	**paths;
	char	*pval;
	char	*fpath;
	int		cnt;

	fpath = NULL;
	cnt = 0;
	if ((pval = get_env_val(tenv, "PATH")) == NULL)
		return (NULL);
	if ((paths = ft_strsplit(pval, ':')) == NULL)
		return (NULL);
	while (paths[cnt] != NULL)
	{
		if ((fpath = get_fpath(paths[cnt], pname)) != NULL)
			break ;
		cnt++;
	}
	ft_strdel(&pval);
	ft_starfree(paths);
	return (fpath);
}

static char	*verify_path(t_env *tenv, char **args)
{
	char *path;

	if ((path = get_prog_path(tenv, args[0])) != NULL)
	{
		return (path);
	}
	else if ((access(args[0], F_OK) == 0) && (access(args[0], X_OK) == 0))
	{
		path = ft_strdup(args[0]);
		return (path);
	}
	else
	{
		return (NULL);
	}
}

char		**tenv_to_star(t_env *tenv)
{
	char	**star;
	char	*tmp;
	int		cnt;
	size_t	varlen;
	size_t	vallen;

	cnt = 0;
	varlen = ft_strlen(tenv->var);
	vallen = ft_strlen(tenv->val);
	star = (char **)malloc(sizeof(*star) * (tenv_count(tenv) + 1));
	while (tenv != NULL)
	{
		tmp = ft_strjoin(tenv->var, "=");
		star[cnt] = ft_strjoin(tmp, tenv->val);
		ft_strdel(&tmp);
		cnt++;
		tenv = tenv->next;
	}
	star[cnt] = NULL;
	return (star);
}

int			msh_exec(char **args, t_env *tenv)
{
	char	*path;
	char	**env;
	pid_t	pid;

	if ((path = verify_path(tenv, args)) == NULL)
		return (-1);
	env = tenv_to_star(tenv);
	pid = fork();
	if (pid == 0)
	{
		execve(path, args, env);
		exit(0);
	}
	if (pid > 0)
		waitpid(pid, 0, 0);
	ft_strdel(&path);
	ft_starfree(env);
	return (0);
}
