/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:03:55 by bsirikam          #+#    #+#             */
/*   Updated: 2022/11/23 17:35:56 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*just_read(int fd, char *line)
{
	char	*tmp;
	ssize_t	n;
	size_t	len_new;

	n = 1;
	len_new = 0;
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while ((!line || (line[ft_strchr(line, '\n')] != '\n')) && n > 0)
	{
		n = read(fd, tmp, BUFFER_SIZE);
		if (n == -1)
			break;
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
	size_t	len_new;

	len_new = ft_strchr(line, '\n');
	i = 0;
	if (len_new == 0)
		result = (char *)malloc(sizeof(char) * (len_new + 1));
	else if (len_new > 0)
	{
		result = (char *)malloc(sizeof(char) * (len_new + 1));
		result[len_new] = '\n';
		result[len_new + 1] = '\0';
	}
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
	{
		return (NULL);
	}
	if (!line || line[ft_strchr(line, '\n')] != '\n')
		line = just_read(fd, line);
	if (ft_strlen(line) == 0)
		return (NULL);
	res = find_result(line);
	line = find_line(line);
	return (res);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = open("./gnlTester/files/nl", O_RDONLY);
// 	printf("fd  %d\n", fd);
// 	s = get_next_line(fd);
// 	// printf("%s", s);
// 	free(s);
// 	close(fd);
// }
