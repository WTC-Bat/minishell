#include "libft.h"

void	ft_starfree(char **star)
{
	int		cnt;

	cnt = 0;
	while (star[cnt] != NULL)
	{
		ft_strdel(&star[cnt]);
		cnt++;
	}
	free(star);
}
