/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:25:49 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/09 14:26:12 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_endswith(char *str, char *end)
{
	int		strlen;
	int		endlen;
	int		cnt;
	int		ecnt;

	strlen = ft_strlen(str);
	endlen = ft_strlen(end);
	cnt = strlen - endlen;
	ecnt = 0;
	while (cnt < strlen)
	{
		if (str[cnt] != end[ecnt])
			return (0);
		cnt++;
		ecnt++;
	}
	return (1);
}
