/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:03:55 by bsirikam          #+#    #+#             */
/*   Updated: 2022/11/23 17:03:57 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*just_read(int fd, char *line)
{
	char	*tmp;
	int		n;
	size_t	len_new;

	n = 1;
	len_new = 0;
	if (!line)
		line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while (n > 0 && (tmp[ft_strchr(tmp, '\n')] != '\n' \
		|| tmp[ft_strchr(tmp, '\0')] != '\0'))
	{
		n = read(fd, tmp, BUFFER_SIZE);
		tmp[n] = '\0';
		len_new = ft_strchr(tmp, '\n');
		line = ft_strjoin(line, tmp);
		if (len_new > 0)
			break ;
	}
	free(tmp);
	return (line);
}

char	*find_result(char *line)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(sizeof(char) * (ft_strchr(line, '\n') + 1));
	while (line[i] != '\n' && line[i] != '\0')
	{
		result[i] = line[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*find_line(char *line)
{
	char	*resline;
	size_t	newnum;
	size_t	resnum;
	size_t	i;

	resline = NULL;
	i = 0;
	newnum = ft_strchr(line, '\n') + 1;
	resnum = ft_strchr(line, 0) - ft_strchr(line, '\n');
	resline = (char *)malloc(sizeof(char) * (resnum + 1));
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
	static char	*line;
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	line = just_read(fd, line);
	if (ft_strlen(line) == 0)
		return (NULL);
	res = find_result(line);
	line = find_line(line);
	return (res);
}

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	close(fd);
}
