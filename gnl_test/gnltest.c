/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnltest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:37:53 by bsirikam          #+#    #+#             */
/*   Updated: 2022/11/23 01:08:50 by bsirikam         ###   ########.fr       */
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
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while (n > 0 && tmp[ft_strchr(tmp, '\n')] != '\n' \
		&& tmp[ft_strchr(tmp, '\0')] != '\0')
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
	result = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[i] != '\n' && line[i] != '\0')
	{
		result[i] = line[i];
		i++;
	}
	result[i] = '\0';
	// printf("%s\n", result);
	return (result);
}

char	*find_line(char * line)
{
	return (NULL);
}

char	*gnl(int fd)
{
	static char	*line;
	char		*res;
	char		*left;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	// line[0] = '\0';
	line = just_read(fd, line);
	if (ft_strlen(line) == 0)
		return (NULL);
	// printf("%s\n", line);
	res = find_result(line);
	// line = find_line(line);
	printf("%zu\n", ft_strlen(res));
	return (res);
}

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	s = gnl(fd);
	// s = gnl(fd);
	// printf("%s\n", s);
	// s = gnl(fd);
	// printf("%s\n", s);
	free(s);
	close(fd);
}
