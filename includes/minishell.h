#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct	s_env
{
	char		*variable;
	char		*value;
	s_env		*next;
}				t_env;

#endif
