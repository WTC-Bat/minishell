/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:18:41 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:18:44 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*istr;

	istr = (char *)malloc(sizeof(char) * 32);
	if (n == 0)
		*--istr = '0' + n;
	if (n >= 0)
	{
		while (n != 0)
		{
			*--istr = '0' + (n % 10);
			n = n / 10;
		}
	}
	else
	{
		while (n != 0)
		{
			*--istr = '0' - (n % 10);
			n = n / 10;
		}
		*--istr = '-';
	}
	istr[ft_strlen(istr)] = '\0';
	return (istr);
}
