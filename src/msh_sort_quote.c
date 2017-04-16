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

static char		quote_char(char *str)
{
	int		first;
	int		last;

	first = ft_indexof(str, '\'');
	last = ft_lindexof(str, '\'');
	if (first > -1 && last > -1 && first != last)
		return ('\'');
	first = ft_indexof(str, '\"');
	last = ft_lindexof(str, '\"');
	if (first > -1 && last > -1 && first != last)
		return ('\"');
	return ('\0');
}

// static char		quote_char(char *str)
// {
// 	int		first;
// 	int		last;
//
// 	first = ft_indexof(str, '\'');
// 	last = ft_lindexof(str, '\'');
// 	if (first > -1 && last > -1 && first != last)
// 	{
// 		if (char_is_in_quote('\'', first, str) == 0)
// 			return ('\'');
// 	}
// 	first = ft_indexof(str, '\"');
// 	last = ft_lindexof(str, '\"');
// 	if (first > -1 && last > -1 && first != last)
// 	{
// 		if (char_is_in_quote('\"', first, str) == 0)
// 			return ('\"');
// 	}
// 	return ('\0');
// }

static void	set_start_end(char *input, int *start, int *end, int idx, char quot)
{
	if (input[idx] != ' ' && *start == -1)
		*start = idx;
	if (input[idx] == ' ' && quot == '\0' && idx > 0)
		*end = idx - 1;
	else if (input[idx + 1] == '\0')
		*end = idx;
}

static char	*get_sorted_segment(char *input, int wstart, int wend)
{
	char *sub;
	char *sort;

	if (input == NULL)
		return (NULL);
	sub = ft_strsub(input, wstart, (wend - wstart + 1));
	if (quote_char(sub) != '\0')
		sort = quote_trim(sub, quote_char(sub));
	else
		sort = ft_strdup(sub);
	ft_strdel(&sub);
	return (sort);
}

static char	**get_sorted(char *input, int *wstart, int *wend, int *qcnt)
{
	char	**sorted;
	int		idx;
	char	curquot;

	idx = 0;
	sorted = (char **)malloc(sizeof(*sorted) * wdcnt(input) + 1);
	curquot = '\0';
	while (input[idx] != '\0')
	{
		set_start_end(input, wstart, wend, idx, curquot);
		if (*wstart > -1 && *wend > -1)
		{
			sorted[*qcnt] = get_sorted_segment(input, *wstart, *wend);
			*qcnt += 1;
			reset_start_end(wstart, wend);
		}
		curquot = check_quote(input[idx], curquot);
		idx++;
	}
	sorted[*qcnt] = NULL;
	return (sorted);
}

char		**msh_sort_quote(char *input)
{
	char	**sorted;
	int		wstart;
	int		wend;
	int		qcnt;

	if (input == NULL || input[0] == '\0')
		return (NULL);
	wstart = -1;
	wend = -1;
	qcnt = 0;
	sorted = get_sorted(input, &wstart, &wend, &qcnt);
	return (sorted);
}
