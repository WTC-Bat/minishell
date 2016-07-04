#include "../libft/libft.h"
#include "../includes/minishell.h"

static int		handle_input(char **args, t_env *tenv)
{
	int		done;

	done = 0;
	if ((ft_strequ(args[0], "env")) == 1)
		print_env(tenv);
	else if ((ft_strequ(args[0], "echo")) == 1)
		msh_echo(args);
	else if ((ft_strequ(args[0], "setenv")) == 1)
		msh_setenv(&tenv, args);
	else if ((ft_strequ(args[0], "unsetenv")) == 1)
		msh_unsetenv(&tenv, args);
	else if ((ft_strequ(args[0], "exit")) == 1)
		done = 1;
	else
	{
		ft_putstr(args[0]);
		ft_putendl(": Unknown command");
	}
	return (done);
}

static void	put_prompt(t_env *tenv)
{
	char	*prompt;
	char	*user;

	user = get_env_val(tenv, "USER");
	prompt = ft_strdup(COL_HGRN_BLD);
	prompt = ft_strjoin(prompt, user);
	prompt = ft_strjoin(prompt, "@WTC $> ");
	prompt = ft_strjoin(prompt, COL_DEF);
	free(user);
	ft_putstr(prompt);
	free(prompt);
}

static int	has_arg(char **argv, char c)
{
	int		scnt;
	int		cnt;

	scnt = 0;
	cnt = 0;
	while (argv[scnt] != NULL)
	{
		if (argv[scnt][0] == '-')
			while (argv[scnt][cnt] != '\0')
			{
				if (argv[scnt][cnt] == c)
					return (1);
				cnt++;
			}
		cnt = 0;
		scnt++;
	}
	return (0);
}

//
static void	plines(char **lines)
{
	int		scnt;
	int		ccnt;

	scnt = 0;
	ccnt = 0;
	ft_putendl("|||");
	while (lines[scnt] != NULL)
	{
		while (lines[scnt][ccnt] != '\0')
		{
			ft_putchar(lines[scnt][ccnt]);
			ccnt++;
		}
		scnt++;
	}
	ft_putendl("|||");
}
//

int		main(int argc, char **argv)
{
	int		done;
	char	**lines;
	char	**args;
	t_env	*tenv;

	if (argc < 1)
	{
		ft_putendl("???");
		return (1);
	}
	done = 0;
	tenv = get_env();
	if (has_arg(argv, 'c') == 1)
		ft_putstr(TRM_CLR);
	while (done == 0)
	{
		put_prompt(tenv);
		lines = (char **)malloc(sizeof(char**));//!!?
		get_next_line(0, &*lines);
		plines(lines);
		if (lines[0][0] != '\0')
		{
			args = ft_strsplit(lines[0], ' ');
			done = handle_input(args, tenv);
			//free(lines);
			//free(args);
		}
	}
	//free(args);//?
	//free(tenv);//?
	return (0);
}
