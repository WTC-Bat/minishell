#ifndef MINISHELL_H
# define MINISHELL_H

# define COL_HGRN_BLD "\x1b[92;1m"
# define COL_DEF "\x1b[0m"
# define TRM_CLR "\e[1;1H\e[2J"

typedef struct		s_env
{
	char			*var;
	char			*val;
	struct s_env	*next;
}					t_env;

typedef struct		s_msh
{
	char			*cur_path;
	char			*prev_cmd;
}					t_msh;

t_env	*get_env();
char	*get_env_val(t_env *tenv, char *varname);
void	msh_echo(char **eargv);
void	msh_setenv(t_env **tenv, char **args);
void	msh_unsetenv(t_env **tenv, char **args);
void	print_env(t_env *tenv);
int		strcnt(char **args);
t_env	*t_env_reverse(t_env *tenv);

#endif
