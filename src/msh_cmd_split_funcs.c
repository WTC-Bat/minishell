/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cmd_split_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 08:12:28 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/01/11 08:12:30 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	valid_char(char c)
{
	if (ft_isascii(c) == 1 && ft_iswhitespace(c) == 0)
		return (1);
	return (0);
}

int			get_sc_split_count(char *input)
{
	char	**splits;
	int		idx;
	int		cidx;
	int		cnt;

	splits = ft_strsplit(input, ';');
	idx = 0;
	cidx = 0;
	cnt = 0;
	while (splits[idx] != NULL)
	{
		while (splits[idx][cidx] != '\0')
		{
			if (valid_char(splits[idx][cidx++]) == 1)
			{
				cnt++;
				break ;
			}
			cidx++;
		}
		cidx = 0;
		idx++;
	}
	ft_starfree(splits);
	return (cnt);
}

static char	**do_split(char *input, char **rawsplits)
{
	int		idx;
	int		cidx;
	int		scnt;
	char	**splits;

	idx = 0;
	cidx = 0;
	scnt = 0;
	splits = (char **)malloc(sizeof(*splits) * get_sc_split_count(input) + 1);
	while (rawsplits[idx] != NULL)
	{
		while (rawsplits[idx][cidx] != '\0')
		{
			if (valid_char(rawsplits[idx][cidx++]) == 1)
			{
				splits[scnt++] = ft_strtrim(rawsplits[idx]);
				break ;
			}
			cidx++;
		}
		cidx = 0;
		idx++;
	}
	splits[scnt] = NULL;
	return (splits);
}

char		**semicolon_split(char *input)
{
	char	**rawsplits;
	char	**splits;

	rawsplits = ft_strsplit(input, ';');
	splits = do_split(input, rawsplits);
	ft_starfree(rawsplits);
	return (splits);
}
