/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:27:09 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/01/03 13:27:11 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_starlen(char **star)
{
	int		len;

	len = 0;
	if (star == NULL || star[0] == NULL)
		return (len);
	while (star[len] != NULL)
		len++;
	return (len);
}
