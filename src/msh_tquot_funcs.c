#include "minishell.h"

t_quot	*tquot_init(char *input)
{
	t_quot	*tquot;

	tquot = (t_quot *)malloc(sizeof(t_quot));
	tquot->input = ft_strdup(input);
	return (tquot);
}

void	tquot_free(t_quot *tquot)
{
	if (tquot != NULL)
	{
		if (tquot->input != NULL)
		{
			ft_strclr(tquot->input);
			free(tquot->input);
			tquot->input = NULL;
		}
		free(tquot);
	}
}
