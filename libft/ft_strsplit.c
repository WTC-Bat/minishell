/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:16:03 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/03 13:38:26 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char c)
{
	int		cnt;
	int		wcnt;

	cnt = 0;
	wcnt = 0;
	while (str[cnt] != '\0')
	{
		if (str[cnt] != c && (str[cnt + 1] == c ||
			str[cnt + 1] == '\0'))
			wcnt++;
		cnt++;
	}
	return (wcnt);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**strs;
	size_t	scnt;
	size_t	strcnt;
	size_t	start;

	scnt = 0;
	strcnt = 0;
	start = 0;
	strs = (char **)malloc(sizeof(*strs) * (word_count(s, c) + 1));
	while (s[scnt] != '\0')
	{
		if (s[scnt] != c)
		{
			if (s[scnt - 1] == c || s[scnt - 1] == '\0')
				start = scnt;
			if (s[scnt + 1] == c || s[scnt + 1] == '\0')
				strs[strcnt++] = ft_strsub(s, start, scnt - start + 1);
		}
		scnt++;
	}
	strs[strcnt] = NULL;
	return (strs);
}
