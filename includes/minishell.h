/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 16:15:33 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/07/10 16:15:34 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define COL_HGRN_BLD "\x1b[92;1m"
# define COL_DEF "\x1b[0m"
# define TRM_CLR "\e[1;1H\e[2J"

# include <sys/wait.h>
# include <sys/stat.h>

typedef struct		s_env
{
	char			*var;
	char			*val;
	struct s_env	*next;
}					t_env;

//void				clear_args(char ***args);
void				clear_star(char **args);
void				free_star(char **star);
void				free_tenv(t_env *tenv);
t_env				*get_env();
char				*get_env_val(t_env *tenv, char *varname);
void				msh_cd(char **args, t_env *tenv);
void				cd_navigate(char *arg, t_env *tenv);
void				msh_echo(char **eargv);
int					msh_exec(char **args, t_env *tenv);
////int					msh_exec(t_env *tenv);
void				msh_setenv(t_env **tenv, char **args);
void				msh_unsetenv(t_env **tenv, char **args);
void				print_env(t_env *tenv);
char				*read_line(const int fd);
void				replace_var(t_env **tenv, char *var, char *val);
int					strcnt(char **args);
int					tenv_count(t_env *tenv);
t_env				*t_env_reverse(t_env *tenv);
char				**tenv_to_star(t_env *tenv);

#endif
