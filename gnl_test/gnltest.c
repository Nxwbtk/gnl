#include "get_next_line.h"

char	*build(char *buff)
{
	char	*new;

	if (buff)
		return (buff);
	new = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	return (new);
}

char	*go_read(int fd)
{
	char	*buff;
	char	*next;
	size_t	len_nl;

	buff = build(buff);
	read(fd, buff, BUFFER_SIZE);
	len_nl = ft_strchr(buff, '\n');
	if (len_nl > 0)
	{
		buff[len_nl] = '\0';
		next = ft_strjoin("", buff + len_nl + 1);
	}
	return (buff);
}

char	*gnl(int fd)
{
	static char	*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!line)
		line = build(line);
	buff = go_read(fd);
	line = ft_strjoin(line, buff);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	// printf("%d\n", fd);
	s = gnl(fd);
	printf("%s\n", s);
	// s = gnl(fd);
	// printf("%s\n", s);
	free(s);
	close(fd);
}
