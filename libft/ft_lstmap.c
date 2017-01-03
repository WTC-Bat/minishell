/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:25:31 by mvanwyk           #+#    #+#             */
/*   Updated: 2017/01/03 13:25:34 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*tmp;

	newlist = NULL;
	tmp = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if ((newlist = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		newlist = f(lst);
		newlist->next = tmp;
		tmp = newlist;
		lst = lst->next;
	}
	return (newlist);
}
