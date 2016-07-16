/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_bltn_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 15:55:25 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/07/10 15:55:27 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/minishell.h"

void	msh_echo(char **eargv)
{
	int		cnt;

	cnt = 1;
	while (eargv[cnt] != NULL)
	{
		ft_putstr(eargv[cnt]);
		ft_putchar(' ');
		cnt++;
	}
	ft_putchar('\n');
}
