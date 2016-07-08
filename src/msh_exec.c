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

static char *get_prog_path(t_env *tenv, char *pname)
{
	char	**paths;
	char	*pval;
	char	*fpath;
	char	*ammendpn;

	pval = get_env_val(tenv, pname);
	if (pname[0] != '/')
	{
		ammendpn = ft_prependc(pname, '/');
		free(pname);
	}
	paths = ft_strsplit(pval, ':');
	while (paths != NULL)
	{
		fpath = ft_strjoin(*paths, ammendpn);

		//alt join:
		//	do not use ammendpn
		//	fpath = ft_strjoin(*paths, "/");
		//	ft_strcat(fpath, pname);

		//check acces on 'fpath'
		//if fpath exists
		//	if fpath is executable
		paths++;
	}
}

//int
void	msh_exec(char *pname, char	**args, t_env *tenv)
{

}
