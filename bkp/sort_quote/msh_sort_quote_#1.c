#include "minishell.h"

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

static char	*no_quote_sub(char const *str, int start, size_t len, char curquot)
{
	size_t	cnt;
	char	*sub;

	if (!str)
		return (NULL);
	cnt = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (cnt < len)
	{
		if (str[start + cnt] != curquot)
			sub[cnt] = str[start + cnt];
		cnt++;
	}
	sub[cnt] = '\0';
	return (sub);
}

/*
**	-----------------------------------------------
**	handle empty input
**	-----------------------------------------------
*/

static int	wcnt(char *input)
{
	char	curquot;
	int		idx;
	int		wcnt;

	curquot = '\0';
	idx = 0;
	wcnt = 0;						//Always at least 1? Maybe?
	while (input[idx] != '\0')
	{
		if (input[idx] == ' ' && curquot == '\0')	//&& input[idx - 1] && idx > 0?
			wcnt++;
		if (input[idx] == curquot)
		{
			if (input[idx + 1] == ' ')
			{
				wcnt++;
				curquot = '\0';
				idx++;
			}
		}
		curquot = check_quote(input[idx], curquot);
		idx++;
	}
	if (idx > 0)
		wcnt++;
	return (wcnt);
}

/*
**	-----------------------------------------------
**	are the alternative quotes being handled
**	properly?
**	-----------------------------------------------
**	no "dquot" handling (odd number of the same quote)
**	-----------------------------------------------
**	handle empty input
**	-----------------------------------------------
**
**
**	-----------------------------------------------
**	Something weird going on. Test, and see that
**	sometimes the last char in complex combination
**	will be missing. Things like that
**	-----------------------------------------------
*/
char		**msh_sort_quote(char *input)
{
	//WCNT_TEST
	//WCNT_TEST

	char	**sorted;
	char	curquot;
	int		idx;
	int		wstart;
	int		wend;
	int		qcnt;

	char	tmpquot;

	// ft_putendl("MSH_SORT_QUOTE");

	curquot = '\0';
	idx = 0;
	wstart = -1;
	wend = -1;
	qcnt = 0;
	tmpquot = '\0';
	sorted = (char **)malloc(sizeof(*sorted) * wcnt(input) + 1);
	/*
	**	Test that sorted is not NULL. Also check that wcnt didn't return 0
	*/
	while (input[idx] != '\0')
	{
		curquot = check_quote(input[idx], curquot);

		// ft_putstr("CURQUOT: ");
		// ft_putchar(curquot);
		// ft_putchar('\n');

		if (curquot != '\0' && input[idx] == curquot)
		{
			tmpquot = curquot;
			qcnt++;
			if (qcnt == 1)
			{
				if (input[idx + 1] != curquot)
				{
					wstart = idx + 1;
				}
			}
			else if (qcnt == 2)
			{
				if (input[idx + 1] == ' ')
				{
					wend = idx;	// - 1?
					// idx++;
					// qcnt = 0;	//Not Here!?
				}
				qcnt = 0;	//Here?
			}
		}
		else if (curquot == '\0' && (input[idx] == ' ' || input[idx + 1] == '\0'))
		{
			if (wend == -1)
			{
				if (input[idx + 1] == '\0')
					wend = idx;
				else
					wend = idx - 1;
			}
		}
		// else if (curquot == '\0' && wstart < 0)
		else if (idx == 0 && input[idx] != curquot)
		{
			wstart = idx;
		}
		if (wstart != -1 && wend != -1)
		{
			// *sorted = ft_strsub(input, wstart, ((size_t)(wend - wstart) + 1));
			// *sorted = ft_strsub(input, wstart, (wend - wstart) + 1);
			*sorted = no_quote_sub(input, wstart, (wend - wstart) + 1, tmpquot);

			ft_putendl(*sorted);
			// ft_putendl("*sorted stored");

			tmpquot = '\0';

			sorted++;
			wstart = -1;
			wend = -1;
		}
		idx++;

		// ft_putendl("LOOPED!");
	}
	*sorted = NULL;
	return (sorted);
}



// char		**msh_sort_quote(char *input)
// {
// 	//WCNT_TEST
// 	//WCNT_TEST
//
// 	char	**sorted;
// 	char	quottyp;
// 	int		idx;
// 	int		wstart;
// 	int		wend;
//
// 	quottyp = '\0';
// 	idx = 0;
// 	wstart = -1;
// 	wend = -1;
// 	sorted = (char **)malloc(sizeof(*sorted) * wcnt(input) + 1);
// 	while (input[idx] != '\0')
// 	{
// 		curquot = check_quote(input[idx], curquot);
// 		idx++;
// 	}
// }
