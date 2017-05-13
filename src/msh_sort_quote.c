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
// 		*start = idx;
// 	if (input[idx + 1] == '\0')
// 		*end = idx;
// 	if (quot == '\0')
// 	{
// 		if (input[idx] == ' ' && idx > 0)
// 			*end = idx - 1;
// 		// below: and also check if the next character is a quote?
// 		else if ((input[idx] == '\'' || input[idx] == '\"') && idx != *start)
// 		{
// 			*end = idx - 1;
//
// 			// if (input[idx + 1] != input[idx])
// 			// 	*end = idx - 1;
// 		}
// 	}
// 	else
// 	{
// 		if (input[idx] == quot)		//&& idx < *start //?
// 			*end = idx;
// 	}
// }

static char	*get_sorted_segment(char *input, int wstart, int wend)
{
	char	*sub;
	char	*sort;

	if (input == NULL)
		return (NULL);
	//NEW
	// if ((wend - wstart) == 2)
	// if ((wend - wstart) <= 2) //1?
	if (wend <= wstart)
		return (NULL);
	//NEW
	//TEST
	// ft_putnbr_endl(wend);
	// ft_putnbr_endl(wstart);
	//TEST
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
	char	*tmp;

	idx = 0;
	sorted = (char **)malloc(sizeof(*sorted) * wdcnt(input) + 1);
	curquot = '\0';
	tmp = NULL;
	while (input[idx] != '\0')
	{
		set_start_end(input, wstart, wend, idx, curquot);
		if (*wstart > -1 && *wend > -1)
		{
			tmp = get_sorted_segment(input, *wstart, *wend);
			//
			// ft_putchar('|');
			// ft_putstr(tmp);
			// ft_putchar('|');
			// ft_putchar('\n');
			//
			// if (tmp != NULL)
			if (tmp != NULL)
			{
				// sorted[*qcnt] = ft_strdup(tmp);
				sorted[*qcnt] = ft_strtrim(tmp);
				*qcnt += 1;
				reset_start_end(wstart, wend);
				ft_strdel(&tmp);
			}
			// ft_strdel(&tmp);

			//////OG
			// sorted[*qcnt] = get_sorted_segment(input, *wstart, *wend);
			// *qcnt += 1;
			// reset_start_end(wstart, wend);
			//////
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
