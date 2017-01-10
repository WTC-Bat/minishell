#include "minishell.h"

void		cmds_free(t_list *cmds)
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

static int	get_sc_split_count(char *input)
{
	char	**splits;
	int		idx;
	int		cidx;
	int		cnt;

	splits = ft_strsplit(input, ';');
	idx = 0;
	cidx = 0;
	cnt = 0;
	while (splits[idx] != NULL)
	{
		while (splits[idx][cidx] != '\0')
		{
			if (ft_isascii(splits[idx][cidx]) == 1
				&& ft_iswhitespace(splits[idx][cidx++]) == 0)
			{
				cnt++;
				break ;
			}
			cidx++;
		}
		cidx = 0;
		idx++;
	}
	ft_starfree(splits);
	return (cnt);
}

/*
**	splits input at the sei colons. but still need to check if the semi colon
**	is enclosed in quotes
*/
static char	**semicolon_split(char *input)
{
	int		idx;
	int		cidx;
	int		scnt;
	char	**splits;
	char	**rawsplits;

	idx = 0;
	cidx = 0;
	scnt = 0;
	splits = (char **)malloc(sizeof(*splits) * get_sc_split_count(input) + 1);
	rawsplits = ft_strsplit(input, ';');
	while (rawsplits[idx] != NULL)
	{
		while (rawsplits[idx][cidx] != '\0')
		{
			if (ft_isascii(rawsplits[idx][cidx]) == 1
				&& ft_iswhitespace(rawsplits[idx][cidx++]) == 0)
			{
				splits[scnt++] = ft_strtrim(rawsplits[idx]);
				break ;
			}
			cidx++;
		}
		cidx = 0;
		idx++;
	}
	splits[scnt] = NULL;
	ft_starfree(rawsplits);
	return (splits);
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

/* Rewrite using ft_lstnew with ft_lstadd? */
t_list	*msh_cmd_split(char *input)
{
	t_list	*cmds;
	t_list	*root;
	char	**scsplits;
	char	*trim;
	int		cnt;

	root = NULL;
	scsplits = semicolon_split(input);
	cnt = 0;
	while (scsplits[cnt] != NULL)
	{
		/*?-- check quotes? --?*/
		trim = ft_strtrim(scsplits[cnt]);
		cmds = ft_lstnew((void *)trim, ft_strlen(trim));
		cmds->next = root;
		root = cmds;
		ft_strdel(&trim);
		cnt++;
	}
	ft_starfree(scsplits);
	return (cmds_reverse(root));
}
