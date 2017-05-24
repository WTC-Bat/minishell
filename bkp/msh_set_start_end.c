/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_set_start_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:18:46 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/05/24 14:19:00 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_start(t_quot *tquot, int *start)
{
	int		idx;

	idx = tquot->idx;
	if (tquot->input[idx] != '\0' && tquot->input[idx] != ' ' && *start == -1)
		*start = idx;
}

static void	set_end(t_quot *tquot, int *end, char quot)
{
	int		idx;

	idx = tquot->idx;
	if (tquot->input[idx] == ' ' && quot == '\0' && idx > 0)
		*end = idx - 1;
	else if (tquot->input[idx + 1] == '\0' || tquot->input[idx] == quot)
		*end = idx;
	if (tquot->input[idx] == '\'' || tquot->input[idx] == '\"')
	{
		if (quot == '\0')
		{
			if (tquot->input[idx] == '\'' && tquot->input[idx + 1] == '\'')
				*end = idx - 1;
			else if (tquot->input[idx] == '\"' && tquot->input[idx + 1] == '\"')
				*end = idx - 1;
		}
	}
}

static void	check_start_end(t_quot *tquot, int *start, int *end)
{
	if (*end == *start + 1)
	{
		if (tquot->input[*start] == '\'' && tquot->input[*end] == '\'')
			*start = -1;
		else if (tquot->input[*start] == '\"' && tquot->input[*end] == '\"')
			*start = -1;
	}
	if (*end < *start)
		*end = -1;
}

void		set_start_end(t_quot *tquot, int *start, int *end, char quot)
{
	set_start(tquot, start);
	set_end(tquot, end, quot);
	check_start_end(tquot, start, end);
}




/*
**	Original basis for funtions above. This version DOES NOT have fixes for
**	[echo Cheese"Crackers"]
**	[echo "Cheese"Crackers]
**	[echo "Cheese" and]
*/
// static void	set_start_end(t_quot *tquot, int *start, int *end, char quot)
// {
// 	int		idx;
//
// 	idx = tquot->idx;
// 	if (tquot->input[idx] != '\0' && tquot->input[idx] != ' ' && *start == -1)
// 		*start = idx;
// 	if (tquot->input[idx] == ' ' && quot == '\0' && idx > 0)
// 		*end = idx - 1;
// 	else if (tquot->input[idx + 1] == '\0' || tquot->input[idx] == quot)
// 		*end = idx;
// 	if (tquot->input[idx] == '\'' || tquot->input[idx] == '\"')
// 	{
// 		if (quot == '\0')
// 		{
// 			if (tquot->input[idx] == '\'' && tquot->input[idx + 1] == '\'')
// 				*end = idx - 1;
// 			else if (tquot->input[idx] == '\"' && tquot->input[idx + 1] == '\"')
// 				*end = idx - 1;
// 		}
// 	}
// 	if (*end == *start + 1)
// 	{
// 		if (tquot->input[*start] == '\'' && tquot->input[*end] == '\'')
// 			*start = -1;
// 		else if (tquot->input[*start] == '\"' && tquot->input[*end] == '\"')
// 			*start = -1;
// 	}
// }
