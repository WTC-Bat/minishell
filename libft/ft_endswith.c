/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 17:43:30 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/07/10 17:44:05 by mvanwyk          ###   ########.fr       */
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
