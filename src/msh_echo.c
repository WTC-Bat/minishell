#include "../libft/libft.h"

void	msh_echo(int eargc, char **eargv)
{
	int		cnt;

	cnt = 0;
	while (cnt < eargc)
	{
		ft_putstr(eargv[cnt]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
