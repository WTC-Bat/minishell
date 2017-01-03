/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lindexof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:04:43 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/01/03 13:24:37 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lindexof(char const *str, char c)
{
	int		cnt;

	if (str != NULL && str[0] != '\0' && c != '\0')
	{
		cnt = ft_strlen(str) - 1;
		while (cnt >= 0)
		{
			if (str[cnt] == c)
				return (cnt);
			cnt--;
		}
	}
	return (-1);
}
