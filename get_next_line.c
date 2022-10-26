/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:49:25 by bsirikam          #+#    #+#             */
/*   Updated: 2022/10/26 02:03:11 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ha_nextnaja(char *str, int fd)
{
	char	*new_str;
	char	*torpai;
	char	*buntad;

	new_str = NULL;
	if (ft_strlen(str))
	{
		torpai = ft_strchr(str, '\n');
		if (!torpai)
		{
			new_str = ft_strjoin(str, "");
			
		}
		if (torpai)
		{
			*torpai = '\0';
			buntad = ft_strjoin(str, "\n");
			return (buntad);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{
		str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return (NULL);
		*str = '\0';
	}
	str = ha_nextnaja(str, fd);
	return (NULL);
}
