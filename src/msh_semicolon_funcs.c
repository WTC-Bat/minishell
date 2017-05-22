/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:15:33 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/02/07 16:15:37 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				has_cmd_splitter(char *input)
{
	int		cnt;

	cnt = 0;
	while (input[cnt] != '\0')
	{
		if (input[cnt] == ';')
			if (char_is_in_quote(input[cnt], cnt, input) == 0)
				return (1);
		cnt++;
	}
	return (0);
}

int				get_split_count(char *input)
{
	int		cnt;
	int		idx;

	cnt = 0;
	idx = 0;
	while (input[idx] != '\0')
	{
		if (input[idx] == ';' && input[idx + 1] != '\0')
		{
			if (char_is_in_quote(input[idx], idx, input) == 0)
				cnt++;
		}
		idx++;
	}
	return (cnt + 1);
}

static char		*trim_split(char *input, int start, size_t len)
{
	char	*sub;
	char	*trim;

	sub = ft_strsub(input, start, len);
	trim = ft_strtrim(sub);
	ft_strdel(&sub);
	return (trim);
}

static int		*get_split_indices(char *input)
{
	int		*indices;
	int		idx;
	int		icnt;

	idx = 0;
	icnt = 0;
	indices = (int *)malloc(sizeof(int) * get_split_count(input) + 1);
	while (input[idx] != '\0')
	{
		if (input[idx] == ';')
		{
			if (char_is_in_quote(input[idx], idx, input) == 0)
			{
				indices[icnt] = idx;
				icnt++;
			}
		}
		idx++;
	}
	indices[icnt] = -1;
	return (indices);
}

char			**split_indices(char *input)
{
	char	**splits;
	int		*split_indices;
	int		split_cnt;
	int		idx;
	int		spos;

	split_indices = get_split_indices(input);
	split_cnt = get_split_count(input);
	splits = (char **)malloc(sizeof(*splits) * split_cnt + 1);
	idx = 0;
	spos = 0;
	while (idx < split_cnt)
	{
		if (split_indices[idx] == -1)
			splits[idx] = trim_split(input, spos, ft_strlen(input) - spos + 1);
		else
			splits[idx] = trim_split(input, spos, split_indices[idx] - spos);
		spos = split_indices[idx] + 1;
		idx++;
	}
	free(split_indices);
	splits[idx] = NULL;
	return (splits);
}
