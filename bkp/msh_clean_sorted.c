/*
**	Not in use. When/if deciding to use it, don't forget to add the file
**	to the "Makefile", and add non-static prototypes tp "minishell.h"
*/

#include "minishell.h"

static int	get_next_quote(char *input, char quot, int start)
{
	int		idx;

	idx = start;
	while (input[idx] != '\0')
	{
		if (input[idx] == quot)
			return (idx);
	}
	return (-1);
}

static char	*do_cleaning(char *input, int qidx1, int qidx2)
{
	char	*clean;
	int		in_idx;
	int		clean_idx;

	clean = (char *)malloc(sizeof(char) * ft_strlen(input) - 1);
	if (clean == NULL)
		return (NULL);
	in_idx = 0;
	clean_idx = 0;
	while (input[in_idx] != '\0')
	{
		if (in_idx != qidx1 && in_idx != qidx2)
		{
			clean[clean_idx] = input[in_idx];
			clean_idx++;
		}
		in_idx++;
	}
	clean[clean_idx] = '\0';
	return (clean);
}

int			needs_cleaning(char *input)
{
	int		qidx;

	qidx = -1;
	if ((qidx = ft_indexof(input, '\'')) > -1 || (qidx = ft_indexof(input, '\"')) > -1)
	{
		if (qidx > 0)
		{
			if (char_is_in_quote(input[qidx + 1], qidx + 1, input) == 0)
			{
				if (input[qidx - 1] != ' ')
				{
					return (1);
				}
			}
		}
	}
	return (0);
}

char		*clean_sorted(char *input)
{
	/* check Cheese"Crackers" */
	int		qidx;
	int		next_idx;
	char	*clean;

	qidx = -1;
	clean = NULL;
	if ((qidx = ft_indexof(input, '\'')) > -1 || (qidx = ft_indexof(input, '\"')) > -1)
		if (char_is_in_quote(input[qidx], qidx, input) == 1)
			if ((next_idx = get_next_quote(input, input[qidx], qidx + 1)) > -1)
				if (next_idx > qidx)
					clean = do_cleaning(input, qidx, next_idx);
	return (clean);
}
