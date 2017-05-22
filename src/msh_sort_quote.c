/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:15:33 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/05/22 10:52:03 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	set_start_end(char *input, int *start, int *end, int idx, char quot)
// {
// 	if (input[idx] != '\0' && input[idx] != ' ' && *start == -1)
// 		*start = idx;
// 	if (input[idx] == ' ' && quot == '\0' && idx > 0)
// 		*end = idx - 1;
// 	else if (input[idx + 1] == '\0' || input[idx] == quot)
// 		*end = idx;
// 	if (input[idx] == '\'' || input[idx] == '\"')
// 	{
// 		if (quot == '\0')
// 		{
// 			if (input[idx] == '\'' && input[idx + 1] == '\'')
// 				*end = idx - 1;
// 			else if (input[idx] == '\"' && input[idx + 1] == '\"')
// 				*end = idx - 1;
// 		}
// 	}
// 	if (*end == *start + 1)
// 	{
// 		if (input[*start] == '\'' && input[*end] == '\'')
// 			*start = -1;
// 		else if (input[*start] == '\"' && input[*end] == '\"')
// 			*start = -1;
// 	}
// }

//26 lines
static void	set_start_end(t_quot *tquot, int *start, int *end, char quot)
{
	int		idx;

	idx = tquot->idx;
	if (tquot->input[idx] != '\0' && tquot->input[idx] != ' ' && *start == -1)
		*start = idx;
	if (tquot->input[idx] == ' ' && quot == '\0' && idx > 0)
		*end = idx - 1;
	else if (tquot->input[idx + 1] == '\0' || tquot->input[idx] == quot)
		*end = idx;
	if (tquot->input[idx] == '\'' || tquot->input[idx] == '\"')
	{
		if (quot == '\0')
		{
			if (tquot->input[idx] == '\'' && tquot->input[idx + 1] == '\'')
				*end = idx - 1;
			else if (tquot->input[idx] == '\"' && tquot->input[idx + 1] == '\"')
				*end = idx - 1;
		}
	}
	if (*end == *start + 1)
	{
		if (tquot->input[*start] == '\'' && tquot->input[*end] == '\'')
			*start = -1;
		else if (tquot->input[*start] == '\"' && tquot->input[*end] == '\"')
			*start = -1;
	}
}

static char	*get_sorted_segment(char *input, int wstart, int wend)
{
	char	*sub;
	char	*sort;

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

//38 lines
static char	**get_sorted(char *input, int *wstart, int *wend, int *qcnt)
{
	char	**sorted;
	int		idx;
	char	curquot;
	char	*tmp;
	t_quot	*tquot;

	idx = 0;
	sorted = (char **)malloc(sizeof(*sorted) * wdcnt(input) + 1);
	curquot = '\0';
	tmp = NULL;
	//
	// tquot = (t_quot *)malloc(sizeof(t_quot));
	// tquot->input = ft_strdup(input);
	tquot = tquot_init(input);
	//
	while (input[idx] != '\0')
	{
		tquot->idx = idx;
		set_start_end(tquot, wstart, wend, curquot);
		if (*wstart > -1 && *wend > -1)
		{
			tmp = get_sorted_segment(input, *wstart, *wend);
			if (tmp != NULL && tmp[0] != '\0')
			{
				sorted[*qcnt] = ft_strtrim(tmp);
				*qcnt += 1;
				reset_start_end(wstart, wend);
				ft_strdel(&tmp);
			}
		}
		curquot = check_quote(input[idx], curquot);
		idx++;
	}
	//
	// ft_strclr(tquot->input);
	// free(tquot->input);
	// tquot->input = NULL;
	// tquot = NULL;
	tquot_free(tquot);
	//
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
