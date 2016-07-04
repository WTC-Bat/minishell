#include "../libft/libft.h"

void	msh_echo(char **eargv)
{
	int		cnt;

	cnt = 1;
	while (eargv[cnt] != NULL)
	{
		ft_putstr(eargv[cnt]);
		ft_putchar(' ');
		cnt++;
	}
	ft_putchar('\n');
}
