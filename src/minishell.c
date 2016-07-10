#include "../libft/libft.h"
#include "../includes/minishell.h"

static int	handle_input(char **args, t_env *tenv)
{
	int		done;
	int		exec_err;

	done = 0;
	exec_err = 0;
	if ((ft_strcmp(args[0], "env")) == 0)
		print_env(tenv);
	else if ((ft_strcmp(args[0], "echo")) == 0)
		msh_echo(args);
	else if ((ft_strcmp(args[0], "setenv")) == 0)
		msh_setenv(&tenv, args);
	else if ((ft_strcmp(args[0], "unsetenv")) == 0)
		msh_unsetenv(&tenv, args);
	else if ((ft_strcmp(args[0], "exit")) == 0)
		done = 1;
	else
	{
		if ((exec_err = msh_exec(args, tenv) == -1))
		{
			ft_putstr(args[0]);
			ft_putendl(": Unknown command");
		}
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
	//free(user);
	ft_putstr(prompt);
	//free(prompt);
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

/*
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
		ccnt = 0;
		scnt++;
	}
	ft_putendl("|||");
}
//
*/

int			main(int argc, char **argv)
{
	int		done;
	char	*input;
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
		input = read_line(0);
		if (input[0] != '\0') // && input[0] != '\n'
		{
			args = ft_strsplit(input, ' ');
			//plines(args);
			done = handle_input(args, tenv);
			//free(args);
		}
		//free(input);//?
		//free(args);
	}
	//free(args);//?
	free(tenv);//?
	return (0);
}
