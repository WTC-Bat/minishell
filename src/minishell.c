/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 16:07:04 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/07/10 16:07:05 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/minishell.h"

static int	handle_input(char **args, t_env *tenv)
{
	if ((ft_strcmp(args[0], "env")) == 0)
		print_env(tenv);
	else if ((ft_strcmp(args[0], "echo")) == 0)
		msh_echo(args);
	else if ((ft_strcmp(args[0], "setenv")) == 0)
		msh_setenv(&tenv, args);
	else if ((ft_strcmp(args[0], "unsetenv")) == 0)
		msh_unsetenv(&tenv, args);
	else if (ft_strcmp(args[0], "cd") == 0)
		msh_cd(args, tenv);
	else if ((ft_strcmp(args[0], "exit")) == 0)
		return (1);
	else
	{
		if (msh_exec(args, tenv) == -1)
		{
			ft_putstr(args[0]);
			ft_putendl(": Unknown command");
		}
	}
	return (0);
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
	ft_putstr(prompt);
	free(user);
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

static int	loop(t_env *tenv)
{
	char	*input;
	char	**args;
	int		done;

	done = 0;
	put_prompt(tenv);
	input = read_line(0);
	args = NULL;
	if (input[0] != '\0' && input[0] != ' ' && input[0] != '\t')
	{
		args = ft_strsplit(input, ' ');
		done = handle_input(args, tenv);
	}
	free(input);
	if (args != NULL)
		free(args);
	return (done);
}

int			main(int argc, char **argv)
{
	int			done;
	t_env		*tenv;
	extern char	**environ;

	if (argc < 1)
	{
		ft_putendl("???");
		return (1);
	}
	done = 0;
	tenv = get_env(environ);
	if (has_arg(argv, 'c') == 1)
		ft_putstr(TRM_CLR);
	while (done == 0)
		done = loop(tenv);
	free(tenv);
	return (0);
}
