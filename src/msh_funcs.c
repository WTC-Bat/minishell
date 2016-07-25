/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 16:09:31 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/07/10 16:09:33 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/minishell.h"

int		strcnt(char **args)
{
	int		cnt;

	cnt = 0;
	while (args[cnt] != NULL)
		cnt++;
	return (cnt);
}

char	*read_line(const int fd)
{
	char	inchar;
	char	*line;

	inchar = '0';
	//line = ft_strnew(0);
	//line = (char *)malloc(sizeof(char) * 2);
	line = (char *)malloc(sizeof(char));
	while (inchar != '\n' && inchar != '\0')
	{
		read(fd, &inchar, 1);
		if (inchar != '\n' && inchar != '\0')
			ft_strcat(line, &inchar);
	}
	line[ft_strlen(line)] = '\0';
	return (line);
}

void	free_tenv(t_env *tenv)
{
	t_env	*tmp;

	while (tenv != NULL)
	{
		tmp = tenv;
		tenv = tenv->next;
		//free(tmp->var);
		//free(tmp->val);
		free(tmp);
	}
	tenv = NULL;
}

void	free_star(char **star)
{
	int		cnt;

	cnt = 0;
	while (star[cnt] != NULL)
	{
		//ft_strclr(star[cnt]);
		free(star[cnt]);
		star[cnt] = NULL;
		cnt++;
	}
	////ft_putendl("STAR FREED");
}

void	clear_star(char **star)
{
	int		cnt;

	cnt = 0;
	while (star[cnt] != NULL)
	{
		ft_strclr(star[cnt]);
		cnt++;
	}
}

/*
void	clear_args(char ***args)
{
	int		scnt;
	int		ccnt;

	scnt = 0;
	ccnt = 0;
	while (*args[scnt] != NULL)
	{
		while (*args[scnt][ccnt] != '\0')
		{
			*args[scnt][ccnt] = '\0';
			ccnt++;
		}
		ccnt = 0;
		scnt++;
	}
}
*/
