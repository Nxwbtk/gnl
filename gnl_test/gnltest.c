#include "get_next_line.h"

char	*build(char *buff)
{
	char	*new;

	if (buff != NULL)
		return (buff);
	new = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (new != NULL)
		new[0] = '\0';
	return (new);
}

char	*go_read(int fd)
{
	char	*tmp;
	char	*buff;
	size_t	len_nl;

	buff = build(buff);
	// printf("%s\n", buff);
	tmp = build(tmp);
	// printf("%s\n", tmp);
	while (ft_strchr(tmp, '\n') == 0)
	{
		read(fd, tmp, BUFFER_SIZE);
		// printf("%s\n", tmp);
		if (ft_strchr(tmp, '\n') != 0)
		{
			// printf("%s\n", buff);
			// printf("%zu\n", ft_strchr(tmp, '\n'));
			tmp[ft_strchr(tmp, '\n')] = '\0';
			// printf("%s\n", tmp);
			buff = ft_strjoin(buff, tmp);
			// printf("%s\n", buff);
			return (buff);
		}
		buff = ft_strjoin(buff, tmp);
		// printf("Run again\n");
	}
	return (buff);
}

char	*gnl(int fd)
{
	static char	*line = NULL;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	// printf("%s\n", line);
	if (!line)
		line = build(line);
	// printf("%s\n", line);
	buff = go_read(fd);
	// printf("%s\n", buff);
	printf("%s\n", line);
	line = ft_strjoin(line, buff);
	// printf("%s\n", line);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	// printf("%d\n", fd);
	s = gnl(fd);
	// printf("%s\n", s);
	// s = gnl(fd);
	// printf("%s\n", s);
	free(s);
	close(fd);
}
