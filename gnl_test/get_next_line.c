/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:03:55 by bsirikam          #+#    #+#             */
/*   Updated: 2022/11/24 01:40:28 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*just_read(int fd, char *line)
{
	char	*tmp;
	ssize_t	n;
	ssize_t	len_new;

	n = 1;
	len_new = 0;
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while ((!line || (line[ft_strchr(line, '\n')] != '\n')) && n > 0)
	{
		n = read(fd, tmp, BUFFER_SIZE);
		if (n == -1)
			break ;
		tmp[n] = '\0';
		len_new = ft_strchr(tmp, '\n');
		line = ft_strjoin(line, tmp);
		if (len_new >= 0)
			break ;
	}
	free(tmp);
	return (line);
}

char	*find_result(char *line)
{
	char	*result;
	int		i;
	ssize_t	len_new;

	len_new = ft_strchr(line, '\n');
	i = 0;
	result = (char *)malloc(sizeof(char) * (len_new + 1));
	while (line[i] && line[i] != '\n')
	{
		result[i] = line[i];
		i++;
	}
	result[i] = '\n';
	result[i + 1] = '\0';
	return (result);
}

char	*find_line(char *line)
{
	char	*resline;
	ssize_t	newnum;
	ssize_t	resnum;
	size_t	i;

	resline = NULL;
	i = 0;
	newnum = ft_strchr(line, '\n') + 1;
	resnum = ft_strchr(line, 0) - ft_strchr(line, '\n');
	resline = (char *)malloc(sizeof(char) * (resnum + 1));
	if (!resline)
		return (NULL);
	while (line[newnum])
	{
		resline[i++] = line[newnum++];
	}
	if (line)
		free(line);
	return (resline);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*res;
	char		test;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &test, 1) <= 0)
		return (NULL);
	if (!line)
	{
		line = malloc(1);
		*line = '\0';
	}
	if (!line || line[ft_strchr(line, '\n')] != '\n')
		line = just_read(fd, line);
	res = find_result(line);
	line = find_line(line);
	return (res);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = open("nl", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("|%s|", s);
// 	free(s);
// 	close(fd);
// }
