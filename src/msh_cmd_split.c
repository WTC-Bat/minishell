/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cmd_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 07:37:28 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/01/11 07:37:31 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			cmds_free(t_list *cmds)
{
	t_list	*tmp;

	while (cmds != NULL)
	{
		tmp = cmds;
		cmds = cmds->next;
		ft_memdel(&(tmp)->content);
		free(tmp);
	}
	free(cmds);
}

// static t_list	*cmds_reverse(t_list *cmds)
// {
// 	t_list	*tmp;
// 	t_list	*new;
//
// 	tmp = NULL;
// 	new = NULL;
// 	while (cmds != NULL)
// 	{
// 		tmp = cmds->next;
// 		cmds->next = new;
// 		new = cmds;
// 		cmds = tmp;
// 	}
// 	return (new);
// }

t_list			*msh_cmd_split(char *input)
{
	t_list	*cmds;
	t_list	*root;
	char	**splits;
	char	*trim;
	int		scnt;
	int		idx;

	scnt = get_split_count(input);
	splits = split_indices(input);
	ft_putendl("SPLIT WORK");

	//
	// int i = 0;
	// ft_putendl("SPLITS:");
	// while (splits[i] != NULL)
	// {
	// 	ft_putendl(splits[i]);
	// 	i++;
	// }
	//

	idx = 0;
	root = NULL;
	while (idx < scnt)
	{
		trim = ft_strtrim(splits[idx]);
		// ft_putstr("TRIM: ");
		// ft_putendl(trim);
		cmds = ft_lstnew((void *)trim, ft_strlen(trim));	//+1?
		cmds->next = root;
		root = cmds;
		ft_strdel(&trim);
		idx++;
	}
	// ft_putendl("TRIMMED:");
	// while (root != NULL)
	// {
	// 	ft_putendl((char *)root->content);
	// 	root = root->next;
	// }
	// ft_starfree(splits);
	return (root);
	// return (cmds_reverse(root));
}

// t_list			*msh_cmd_split(char *input)
// {
// 	t_list	*cmds;
// 	t_list	*root;
// 	char	**scsplits;
// 	char	*trim;
// 	int		cnt;
//
// 	root = NULL;
// 	scsplits = semicolon_split(input);
// 	cnt = 0;
// 	while (scsplits[cnt] != NULL)
// 	{
// 		trim = ft_strtrim(scsplits[cnt]);
// 		cmds = ft_lstnew((void *)trim, ft_strlen(trim));
// 		cmds->next = root;
// 		root = cmds;
// 		ft_strdel(&trim);
// 		cnt++;
// 	}
// 	ft_starfree(scsplits);
// 	return (cmds_reverse(root));
// }
