/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:07:34 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/03 14:35:59 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *str)
{
	int		cnt;
	int		stridx;
	char	*rstr;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	cnt = 0;
	stridx = ft_strlen(str) - 1;
	if ((rstr = (char *)malloc(sizeof(char) * stridx + 2)) == NULL)
		return (NULL);
	while (stridx >= 0)
	{
		rstr[cnt] = str[stridx];
		cnt++;
		stridx--;
	}
	rstr[cnt] = '\0';
	return (rstr);
}
