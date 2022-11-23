/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:01:02 by bsirikam          #+#    #+#             */
/*   Updated: 2022/11/24 01:23:42 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

ssize_t	ft_strchr(const char *s, int c)
{
	ssize_t			len_new;

	len_new = 0;
	if (!s)
		return (0);
	while (s[len_new] && s[len_new] != c)
		len_new++;
	return (len_new);
}

char	*lets_join(char *res, char *s1, char *s2)
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
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	s_toml;
	char	*res;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s_toml = s1_len + s2_len;
	res = malloc(s_toml + 1);
	if (!res)
		return (0);
	res = lets_join(res, s1, s2);
	return (res);
}

char	*ft_rejoin(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (s1)
		free (s1);
	return (res);
}
