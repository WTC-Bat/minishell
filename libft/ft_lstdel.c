/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 16:39:55 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/07/10 16:39:57 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while (*alst != NULL)
	{
		del(&(*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
		*alst = (*alst)->next;
	}
}
