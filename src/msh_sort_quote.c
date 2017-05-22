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

static char	*get_sorted_work(char *input, int *wstart, int *wend)
{
	char	*tmp;
	char	*trim;

	trim = NULL;
	if (*wstart > -1 && *wend > -1)
	{
		tmp = get_sorted_segment(input, *wstart, *wend);
		if (tmp != NULL && tmp[0] != '\0')
		{
			trim = ft_strtrim(tmp);
			reset_start_end(wstart, wend);
			ft_strdel(&tmp);
		}
	}
	return (trim);
}

static void	set_sorted(char **sorted, int *qcnt, char *tmp)
{
	sorted[*qcnt] = ft_strdup(tmp);
	*qcnt += 1;
	ft_strdel(&tmp);
}

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
	tquot = tquot_init(input);
	while (input[idx] != '\0')
	{
		tquot->idx = idx;
		set_start_end(tquot, wstart, wend, curquot);
		tmp = get_sorted_work(input, wstart, wend);
		if (tmp != NULL && tmp[0] != '\0')
			set_sorted(sorted, qcnt, tmp);
		curquot = check_quote(input[idx], curquot);
		idx++;
	}
	tquot_free(tquot);
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
