/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:24:41 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/10 17:17:28 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void *s1, void *s2, size_t n)
{
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	while (n != 0)
	{
		if (s1_uc != s2_uc)
			return (s1_uc - s2_uc);
		s1_uc++;
		s2_uc++;
		n--;
	}
	return (0);
}
