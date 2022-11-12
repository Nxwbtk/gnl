#include "get_next_line.h"

char	*go_read(int fd, char *buff)
{
	int		n;
	char	*next;
	size_t	len_nl;
	size_t	buff_len;

	// printf("%d\n", fd);
	(void)buff;
	buff = malloc(BUFFER_SIZE+1);
	n = read(fd, buff, BUFFER_SIZE);
	printf("%s\n", buff);
	buff_len = ft_strlen(buff);
	if (buff_len)
	{
		len_nl = ft_strchr(buff, '\n');
		if (len_nl != 0)
		{
			buff[len_nl] = '\0';
			next = ft_strjoin(buff + len_nl + 1, "");
			return (buff);
		}
		buff[buff_len] = '\0';
	}
	return (buff);
}

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

char	*gnl(int fd)
{
	static char	*line;
	char		*buff;

	// printf("%d\n", fd);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	// buff = build(buff);
	// printf("%d\n", fd);
	buff = go_read(fd, buff);
	if (!line)
	{
		line = ft_strjoin(line, buff);
		return (line);
	}
	else
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
	// printf("%s\n", s);
	free(s);
	close(fd);
}
