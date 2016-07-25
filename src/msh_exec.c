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

#include "../libft/libft.h"
#include "../includes/minishell.h"

static char	*get_prog_path(t_env *tenv, char *pname)
{
	char	**paths;
	char	*pval;
	char	*fpath;

	if ((pval = get_env_val(tenv, "PATH")) != NULL)
	{
		paths = ft_strsplit(pval, ':');
		while (*paths != NULL)
		{
			fpath = ft_strjoin(*paths, "/");
			ft_strcat(fpath, pname);
			if (access(fpath, F_OK) == 0)
				if (access(fpath, X_OK) == 0)
					return (fpath);
				paths++;
		}
		////free_star(paths);
		//free(paths);
		free(pval);
		free(fpath);
		//if (fpath != NULL)
		//	free(fpath);
	}
	return (NULL);
}

char		**tenv_to_star(t_env *tenv)
{
	char	**star;
	int		len;
	int		cnt;
	size_t	varlen;
	size_t	vallen;

	len = tenv_count(tenv);
	cnt = 0;
	varlen = ft_strlen(tenv->var);
	vallen = ft_strlen(tenv->val);
	star = (char **)malloc(sizeof(char *) * len + 1);
	while (tenv != NULL)
	{
		star[cnt] = (char *)malloc(sizeof(varlen + vallen + 2));
		star[cnt] = ft_strjoin(tenv->var, "=");
		star[cnt] = ft_strjoin(star[cnt], tenv->val);//strcat??
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

	if ((path = get_prog_path(tenv, args[0])) == NULL)
	{
		//free(path);
		return (-1);
	}
	env = tenv_to_star(tenv);
	pid = fork();
	if (pid == 0)
	{
		execve(path, args, env);
		exit(0);
	}
	if (pid > 0)
		waitpid(pid, 0, 0);
	free(path);
	free(env);//?
	//free_star(env);
	return (0);
}
