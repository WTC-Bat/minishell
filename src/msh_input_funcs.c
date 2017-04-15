#include "minishell.h"

static int	has_double_scolon(char *input)
{
	int		cnt;

	cnt = 0;
	while (input[cnt] != '\0')
	{
		if (input[cnt] == ';' && scolon_is_in_quote(cnt, input) == 0)
		{
			if (input[cnt + 1] != '\0' && input[cnt + 1] == ';')
			{
				if (scolon_is_in_quote(cnt + 1, input) == 0)
				{
					ft_putendl_fd("Unexpected character ';;'", 2);
					return (1);
				}
			}
		}
		cnt++;
	}
	return (0);
}

int			check_input(char *input)
{
	if (input[0] != '\0' && input[0] != ' ' && input[0] != '\t')
	{
		if (has_double_scolon(input) == 0)
		{
			return (1);
		}
	}
	return (0);
}
