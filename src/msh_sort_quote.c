#include "minishell.h"

static void	reset_start_end(int *wstart, int *wend)
{
	*wstart = -1;
	*wend = -1;
}

static char	check_quote(char in_idx, char curquot)
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

static int	wdcnt(char *input)
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
		{//-
			if (input[idx + 1] == ' ')
			{
				wcnt++;
				curquot = '\0';
				idx++;
			}
		}//-
		curquot = check_quote(input[idx], curquot);
		idx++;
	}
	if (idx > 0)
		wcnt++;
	return (wcnt);
}

static char		*quote_trim(char *str, char quote)
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
	trim = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2) - 1);
	while (str[idx] != '\0')
	{
		if (idx != first && idx != last)
		{
			trim[tridx] = str[idx];
			tridx++;
		}
		idx++;
	}
	return (trim);
}

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

// static int		wrapped(char *str)
// {
// 	if (ft_indexof(str, '\'') > -1 || ft_indexof(str, '\"') > -1)
// 		return (1);
// 	return (0);
//
// 	// int		end;
// 	//
// 	// end = (int)ft_strlen(str) - 1;
// 	// if ((str[0] == '\'' && str[end] == '\'')
// 	// 	|| (str[0] == '\"' && str[end] == '\"'))
// 	// {
// 	// 	return (1);
// 	// }
// 	// return (0);
// }

/*
**	-----------------------------------------------
**	are the alternative quotes being handled
**	properly?
**	-----------------------------------------------
**	no "dquot" handling (odd number of the same quote)
**	-----------------------------------------------
**	handle empty input
**	-----------------------------------------------
*/
// char		**msh_sort_quote(char *input)
// {
// 	char	**sorted;
// 	char	curquot;
// 	int		idx;
// 	int		wstart;
// 	int		wend;
// 	int		qcnt;
//
// 	if (input == NULL || input[0] == '\0')
// 		return (NULL);
// 	curquot = '\0';
// 	idx = 0;
// 	wstart = -1;
// 	wend = -1;
// 	qcnt = 0;
// 	sorted = (char **)malloc(sizeof(*sorted) * wdcnt(input) + 1);
// 	while (input[idx] != '\0')
// 	{
// 		if (input[idx] != ' ' && wstart == -1)
// 			wstart = idx;
// 		if (input[idx] == ' ' && curquot == '\0' && idx > 0)
// 			wend = idx - 1;
// 		else if (input[idx + 1] == '\0')
// 			wend = idx;
// 		if (wstart > -1 && wend > -1)
// 		{
// 			sorted[qcnt] = ft_strsub(input, wstart, (wend - wstart + 1));
// 			qcnt++;
// 			reset_start_end(&wstart, &wend);
// 		}
// 		curquot = check_quote(input[idx], curquot);
// 		idx++;
// 	}
// 	sorted[qcnt] = NULL;
// 	return (sorted);
// }

char		**msh_sort_quote(char *input)
{
	char	**sorted;
	char	curquot;
	char	*sub;
	int		idx;
	int		wstart;
	int		wend;
	int		qcnt;

	if (input == NULL || input[0] == '\0')
		return (NULL);
	curquot = '\0';
	idx = 0;
	wstart = -1;
	wend = -1;
	qcnt = 0;
	sorted = (char **)malloc(sizeof(*sorted) * wdcnt(input) + 1);
	while (input[idx] != '\0')
	{
		if (input[idx] != ' ' && wstart == -1)
			wstart = idx;
		if (input[idx] == ' ' && curquot == '\0' && idx > 0)
			wend = idx - 1;
		else if (input[idx + 1] == '\0')
			wend = idx;
		if (wstart > -1 && wend > -1)
		{
			sub = ft_strsub(input, wstart, (wend - wstart + 1));
			if (quote_char(sub) != '\0')
				sorted[qcnt] = quote_trim(sub, quote_char(sub));
			else
				sorted[qcnt] = ft_strdup(sub);
			ft_strdel(&sub);
			qcnt++;
			reset_start_end(&wstart, &wend);
		}
		curquot = check_quote(input[idx], curquot);
		idx++;
	}
	sorted[qcnt] = NULL;
	return (sorted);
}
