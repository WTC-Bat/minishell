/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:27:09 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/09 14:27:10 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcnt(char *str)
{
	int		cnt;
	int		wcnt;

	cnt = 0;
	wcnt = 0;
	while (str[cnt] != '\0')
	{
		if (str[cnt] != ' ' && str[cnt] != '\n' &&
			str[cnt] != '\t')
			if (str[cnt + 1] == ' ' || str[cnt + 1] == '\n' ||
				str[cnt + 1] == '\t' || str[cnt + 1] == '\0')
				wcnt++;
		cnt++;
	}
	return (wcnt);
}
