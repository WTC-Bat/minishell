/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 16:15:33 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/04 14:23:05 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define COL_HGRN_BLD "\x1b[92;1m"
# define COL_DEF "\x1b[0m"
# define TRM_CLR "\e[1;1H\e[2J"

# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"

typedef struct		s_env
{
	char			*var;
	char			*val;
	struct s_env	*next;
}					t_env;

//
typedef struct		s_quot
{
	char			*input;
	int				idx;
}					t_quot;
//

int				cd_args_valid(char *arg);
int				cd_navigate(char *arg, t_env *tenv);
int				cd_navigate_basic(t_env *tenv, char *arg);
int				cd_navigate_origin_home(t_env *tenv, char *arg);
void			clear_star(char **args);
void			cmds_free(t_list *cmds);
void			free_star(char **star);
void			free_tenv(t_env *tenv);
t_env			*get_env();
char			*get_env_val(t_env *tenv, char *varname);
int				get_sc_split_count(char *input);
void			msh_cd(char **args, t_env *tenv);
t_list			*msh_cmd_split(char *input);
void			msh_echo(t_env *tenv, char **eargv);
int				msh_exec(char **args, t_env *tenv);
int				msh_handle_input(char **args, t_env *tenv);
void			msh_setenv(t_env **tenv, char **args);
void			msh_unsetenv(t_env **tenv, char **args);
int				only_colon(char *input);
void			print_env(t_env *tenv);
char			*read_line(const int fd);
void			replace_var(t_env *tenv, char *var, char *val);
char			**semicolon_split(char *input);
int				strcnt(char **args);
int				tenv_count(t_env *tenv);
t_env			*t_env_reverse(t_env *tenv);
char			**tenv_to_star(t_env *tenv);

char			**msh_sort_quote(char *input);
int				has_cmd_splitter(char *input);
char			**split_indices(char *input);
int				get_split_count(char *input);

int				check_input(char *input);

void			wdcnt_setvars(int *wcnt, char *curquot, int *idx);
void			reset_start_end(int *wstart, int *wend);
char			check_quote(char in_idx, char curquot);
int				wdcnt(char *input);
char			*quote_trim(char *str, char quote);

int				char_is_in_quote(char c, int cidx, char *input);

t_quot			*tquot_init(char *input);
void			tquot_free(t_quot *tquot);
void			set_start_end(t_quot *tquot, int *start, int *end, char quot);

#endif
