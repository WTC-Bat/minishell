#include "../libft/libft.h"

int		strcnt(char **args)
{
	int		cnt;

	cnt = 0;
	while (args[cnt] != NULL)
		cnt++;
	return (cnt);
}
