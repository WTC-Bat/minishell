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

static char *get_prog_path(t_env *tenv, char *pname)
{
	char	**paths;
	char	*pval;
	char	*fpath;
	//char	*ammendpn;

	pval = get_env_val(tenv, "PATH");
	//if (pname[0] != '/')
	//{
	//	ammendpn = ft_prependc(pname, '/');
	//	free(pname);
	//}
	paths = ft_strsplit(pval, ':');
	while (*paths != NULL)
	{
		//fpath = ft_strjoin(*paths, ammendpn);

		//alt join:
		//	do not use ammendpn
		fpath = ft_strjoin(*paths, "/");
		ft_strcat(fpath, pname);

		//check acces on 'fpath'
		//if fpath exists
		//	if fpath is executable
		if (access(fpath, F_OK) == 0)
		{
			//ft_putendl(fpath);
			//ft_putendl("IS FILE");
			if (access(fpath, X_OK) == 0)
			{
				//ft_putchar('\n');
				//ft_putendl(fpath);
				//ft_putendl("IS EXE");
				return (fpath);
			}
		}
		paths++;
		free(fpath);
	}
	return (NULL);
}

char	**tenv_to_star(t_env *tenv)//?
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
		//ft_strcat(star[cnt], tenv->val);
		star[cnt] = ft_strjoin(star[cnt], tenv->val);
		cnt++;
		tenv = tenv->next;
	}
	star[cnt] = NULL;
	return (star);
}

//static void	execute()
//{
//
//}


int		msh_exec(char **args, t_env *tenv)
{
	//char	*pname;
	//char	**pargs;
	char	*path;
	char	**envp;
	int		er;
	pid_t	pid;
	//int		stat;

	er = 0;
	if ((path = get_prog_path(tenv, args[0])) == NULL)
	{
		free(path);
		return (-1);
	}
	//path = get_prog_path(tenv, args[0]);
	//if (path == NULL)
	//	return (-1);
	envp = tenv_to_star(tenv);
	pid = fork();
	if (pid == 0)
		execve(path, args, envp);
		//exit(0);
	if (pid > 0)
		waitpid(pid, 0, 0);
	free(envp);
	return (0);
}
