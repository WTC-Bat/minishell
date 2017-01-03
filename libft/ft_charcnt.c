#include "libft.h"

int		ft_charcnt(char const *str, char c)
{
	int		idx;
	int		cnt;

	cnt = 0;
	if (str != NULL && str[0] != '\0')
	{
		idx = 0;
		while (str[idx] != '\0')
		{
			if (str[idx] == c)
				cnt++;
			idx++;
		}
	}
	return (cnt);
}
