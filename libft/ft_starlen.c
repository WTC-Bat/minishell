#include "libft.h"

int		ft_starlen(char **star)
{
	int		len;

	len = 0;
	if (star == NULL || star[0] == NULL)
		return (len);
	while (star[len] != NULL)
		len++;
	return (len);
}
