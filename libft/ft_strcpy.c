/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:21:24 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/09 10:21:29 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *source)
{
	int		cnt;

	cnt = 0;
	while (source[cnt])
	{
		dest[cnt] = source[cnt];
		cnt++;
	}
	dest[cnt] = '\0';
	return (dest);
}
