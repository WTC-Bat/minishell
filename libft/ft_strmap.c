/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:14:10 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:14:16 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		cnt;
	int		scnt;

	cnt = 0;
	scnt = 0;
	if (!s || !f)
		return (NULL);
	str = (char *)malloc(sizeof(char *) * ft_strlen(s) + 1);
	while (s[cnt] != '\0')
	{
		str[scnt] = f((int)s[cnt]);
		cnt++;
		scnt++;
	}
	str[scnt] = '\0';
	return (str);
}
