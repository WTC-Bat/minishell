/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:19:38 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/09 14:19:40 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_appendc(char *str, int c)
{
	int		len;
	int		cnt;
	char	*out_str;

	len = ft_strlen(str);
	cnt = 0;
	out_str = (char *)malloc(sizeof(char) * (len + 2));
	while (cnt < len)
	{
		out_str[cnt] = str[cnt];
		cnt++;
	}
	out_str[cnt] = c;
	cnt++;
	out_str[cnt] = '\0';
	return (out_str);
}
