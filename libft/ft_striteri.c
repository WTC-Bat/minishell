/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:08:41 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/09 14:17:50 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		cnt;

	if (s == NULL || f == NULL)
		return ;
	cnt = 0;
	while (s[cnt] != '\0')
	{
		f(cnt, (char *)&s[cnt]);
		cnt++;
	}
}
