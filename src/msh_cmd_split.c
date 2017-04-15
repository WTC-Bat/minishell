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

static t_list	*cmds_reverse(t_list *cmds)
{
	t_list	*tmp;
	t_list	*new;

	tmp = NULL;
	new = NULL;
	while (cmds != NULL)
	{
		tmp = cmds->next;
		cmds->next = new;
		new = cmds;
		cmds = tmp;
	}
	return (new);
}

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
	idx = 0;
	root = NULL;
	while (idx < scnt)
	{
		trim = ft_strtrim(splits[idx]);
		cmds = ft_lstnew((void *)trim, ft_strlen(trim) + 1);	//+1?
		cmds->next = root;
		root = cmds;
		ft_strdel(&trim);
		idx++;
	}
	ft_starfree(splits);
	return (cmds_reverse(root));
}
