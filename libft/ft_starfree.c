/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:27:01 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/01/03 13:27:02 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_starfree(char **star)
{
	int		cnt;

	cnt = 0;
	while (star[cnt] != NULL)
	{
		ft_strdel(&star[cnt]);
		cnt++;
	}
	free(star);
}
