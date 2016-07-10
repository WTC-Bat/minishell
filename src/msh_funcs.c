#include "../libft/libft.h"

int		strcnt(char **args)
{
	int		cnt;

	cnt = 0;
	while (args[cnt] != NULL)
		cnt++;
	return (cnt);
}

char	*read_line(const int fd)
{
	char	inchar;
	char	*line;

	inchar = '0';
	line = ft_strnew(1);
	while (inchar != '\n' && inchar != '\0')
	{
		read(fd, &inchar, 1);
		if (inchar != '\n' && inchar != '\0')//?
			ft_strcat(line, &inchar);
	}
	line[ft_strlen(line)] = '\0';
	return (line);
}

void	free_args(char **args)
{
	int		cnt;

	cnt = 0;
	while (args[cnt] != NULL)
	{
		free(args[cnt]);
		cnt++;
	}
	free(args);
}

void	clear_args(char ***args)
{
		int		scnt;
		int		ccnt;

		scnt = 0;
		ccnt = 0;
		while (*args[scnt] != NULL)
		{
			while (*args[scnt][ccnt] != '\0')
			{
				*args[scnt][ccnt] = '\0';
				ccnt++;
			}
			ccnt = 0;
			scnt++;
		}
}
