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

//#1
static void	set_start_end(char *input, int *start, int *end, int idx, char quot)
{
	if (input[idx] != '\0' && input[idx] != ' ' && *start == -1)
		*start = idx;
	if (input[idx] == ' ' && quot == '\0' && idx > 0)
		*end = idx - 1;
	else if (input[idx + 1] == '\0' || input[idx] == quot)
		*end = idx;
}

//#2?
// static void	set_start_end(char *input, int *start, int *end, int idx, char quot)
// {
// 	if (input[idx] != '\0' && input[idx] != ' ' && *start == -1)
// 	{
// 		if (quot == '\0')
// 			*start = idx;
// 	}
// 	if (input[idx] == ' ' && quot == '\0' && idx > 0)
// 	{
// 		*end = idx - 1;
// 	}
// 	else if (input[idx + 1] == '\0' || input[idx] == quot)
// 	{
// 		*end = idx;
// 	}
// }

// static void	set_start_end(char *input, int *start, int *end, int idx, char quot)
// {
//
// }

static char	*get_sorted_segment(char *input, int wstart, int wend)
{
	char *sub;
	char *sort;

	if (input == NULL)
		return (NULL);
	sub = ft_strsub(input, wstart, (wend - wstart + 1));
	if (sub[0] == '\'' || sub[0] == '\"')
		sort = quote_trim(sub, sub[0]);
	else
		sort = ft_strdup(sub);
	ft_strdel(&sub);
	return (sort);
}

// static char	*get_sorted_segment(char *input, int wstart, int wend)
// {
	// char	*sub;
	// char	*sort;
	// char	quote;
	//
	// if (input == NULL)
	// 	return (NULL);
	// sub = ft_strsub(input, wstart, (wend - wstart + 1));
	// sort = NULL;
	// quote = '\0';
	// if (sub[0] == '\'' || sub[0] == '\"')
	// {
	// 	if (sub[0] != sub[1])
	// 	{
	// 		sort = quote_trim(sub, sub[0]);
	// 	}
	// }
	// else if (sub[0] != '\0')
	// {
	// 	sort = ft_strdup(sub);
	// }
	// ft_strdel(&sub);
	// return (sort);
// }

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
			//
			// ft_putnbr_endl(*wstart);
			// ft_putnbr_endl(*wend);
			//
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
