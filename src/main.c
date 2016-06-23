#include "../libft/libft.h"

static int	handle_input(char *in)
{
	int		done;

	done = 0;
	if (ft_strstr(in, "abbacab") != NULL)
		ft_putendl("Skippity Bap m Badap");
	else if (ft_strstr(in, "exit") != NULL)
		done = 1;
	else
		ft_putendl("Excuse you?");	

	return (done);
}

int		main(int argc, char **argv)
{
	int		done;
	ssize_t	rd;
	char	*in;

	done = 0;
	/*write(1, "\e[1;1H\e[2J", 12);*/	/*clear terminal*/
	while (done == 0)
	{
		ft_putstr("$>");
		if ((rd = read(0, (void *)in, 32)) != 0)
			done = handle_input(in);
		else
			done = 1; //!?
	}
	return (0);
}
