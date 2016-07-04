#include "../libft/libft.h"
#include "../includes/minishell.h"

void	msh_echo(char **eargv)
{
	int		cnt;
	//int		len;//

	cnt = 1;
	//len = strcnt(eargv);//
	while (eargv[cnt] != NULL)
	//while (cnt < len)//
	{
		ft_putstr(eargv[cnt]);
		ft_putchar(' ');
		cnt++;
	}
	ft_putchar('\n');
}
