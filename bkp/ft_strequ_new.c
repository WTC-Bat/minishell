int		ft_strequ(char const *s1, char const *s2)
{
	size_t	idx;
	size_t	len1;
	size_t	len2;
	size_t	cnt;

	if (!s1 || !s2)
		return (0);
	idx = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		cnt = len1;
	else
		cnt = len2;
	while (idx < cnt)
	{
		if (s1[idx] != s2[idx] || s1[idx] == '\0' || s2[idx] == '\0')
			return (0);
		idx++;
	}
	return (1);
}
