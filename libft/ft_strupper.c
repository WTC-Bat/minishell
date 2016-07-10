/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 16:38:19 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/07/10 16:38:20 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupper(char const *str)
{
	char	*out_str;
	int		cnt;

	out_str = NULL;
	cnt = 0;
	out_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[cnt] != '\0')
	{
		if (ft_islower(str[cnt]))
			out_str[cnt] = ft_toupper(str[cnt]);
		else
			out_str[cnt] = str[cnt];
		cnt++;
	}
	out_str[cnt] = '\0';
	return (out_str);
}
