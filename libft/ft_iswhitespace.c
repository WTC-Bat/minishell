#include "libft.h"

int		ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\f'
			|| c == '\v')
		return (1);
	return (0);
}
