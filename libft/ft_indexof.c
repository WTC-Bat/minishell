/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:12:52 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/31 17:12:56 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_indexof(char const *str, char c)
{
	int		cnt;

	if (str != NULL && str[0] != '\0' && c != '\0')
	{
		cnt = 0;
		while (str[cnt] != '\0')
		{
			if (str[cnt] == c)
				return (cnt);
			cnt++;
		}
	}
	return (-1);
}
