#include "libft.h"

int		ft_splitcnt(char *str, char c)
{
	int		cnt;
	int		wcnt;

	cnt = 0;
	wcnt = 0;
	while (str[cnt] != '\0')
	{
		if (str[cnt] != c && (str[cnt + 1] == c || str[cnt + 1] == '\0'))
			wcnt++;
		cnt++;
	}
	return (wcnt);
}
