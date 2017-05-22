/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_sort_quote_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 10:51:24 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/05/22 10:51:29 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wdcnt_setvars(int *wcnt, char *curquot, int *idx)
{
	wcnt[0]++;
	*curquot = '\0';
	idx[0]++;
}

void	reset_start_end(int *wstart, int *wend)
{
	*wstart = -1;
	*wend = -1;
}

char	check_quote(char in_idx, char curquot)
{
	if (in_idx == '\'' || in_idx == '\"')
	{
		if (curquot == '\0')
			return (in_idx);
		else if (curquot == in_idx)
			return ('\0');
	}
	return (curquot);
}

int		wdcnt(char *input)
{
	char	curquot;
	int		idx;
	int		wcnt;

	curquot = '\0';
	idx = 0;
	wcnt = 0;
	if (input == NULL || input[0] == '\0')
		return (0);
	while (input[idx] != '\0')
	{
		if (input[idx] == ' ' && curquot == '\0')
			wcnt++;
		if (input[idx] == curquot)
		{
			if (input[idx + 1] == ' ')
				wdcnt_setvars(&wcnt, &curquot, &idx);
		}
		curquot = check_quote(input[idx], curquot);
		idx++;
	}
	if (idx > 0)
		wcnt++;
	return (wcnt);
}

char	*quote_trim(char *str, char quote)
{
	int		idx;
	int		tridx;
	int		first;
	int		last;
	char	*trim;

	idx = 0;
	tridx = 0;
	first = ft_indexof(str, quote);
	last = ft_lindexof(str, quote);
	trim = (char *)malloc(sizeof(char) * (ft_strlen(str) - 2) + 1);
	while (str[idx] != '\0')
	{
		if (idx != first && idx != last)
		{
			trim[tridx] = str[idx];
			tridx++;
		}
		idx++;
	}
	trim[tridx] = '\0';
	return (trim);
}
