/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:01:02 by bsirikam          #+#    #+#             */
/*   Updated: 2022/10/27 18:29:43 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char			*src;
	size_t			s_len;
	unsigned char	cc;

	src = ((char *)s);
	s_len = ft_strlen(src);
	cc = (unsigned char)c;
	if (!c || !s)
		return (src + s_len);
	while (*src)
	{
		if (*src == cc)
			return (src);
		src++;
	}
	return (NULL);
}

char	*lets_join(char *res, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		j++;
		i++;
	}
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	s_toml;
	char	*res;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s_toml = s1_len + s2_len;
	res = malloc(s_toml + 1);
	if (!res)
		return (0);
	res = lets_join(res, s1, s2);
	res[s_toml] = '\0';
	return (res);
}