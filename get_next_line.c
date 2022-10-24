/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:49:25 by bsirikam          #+#    #+#             */
/*   Updated: 2022/10/24 11:56:05 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_build(char *str)
{
	char	*new;

	if (str != NULL)
		return (str);
	new = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new)
		return (NULL);
	if (new)
		*new = '\0';
	return (new);
}

char	*let_read(char *str, int fd)
{
	char	*new_str;

	new_str = NULL;
	if (ft_strlen(str))
	{
		
	}
}

char	*get_next_line(int fd)
{
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_build(str);
	if (!str)
		return (NULL);
	str = let_read(str, fd);
	return (NULL);
}
