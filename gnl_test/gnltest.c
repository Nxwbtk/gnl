#include "get_next_line.h"

char	*go_read(int fd)
{
	char	*tmp;
	char	*buff;
	int		r_size;
	size_t	len_nl;

	buff = NULL;
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	tmp[0] = '\0';
	while (ft_strchr(tmp, '\n') == 0)
	{
		r_size = read(fd, tmp, BUFFER_SIZE);
		tmp[r_size] = '\0';
		buff = ft_strjoin(buff, tmp);
		printf("buff: %s\n", buff);
		if (ft_strchr(tmp, '\n') != 0)
			break;
	}
	if (tmp)
		free(tmp);
	return (buff);
}

char	*gnl(int fd)
{
	static char	*line = NULL;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buff = go_read(fd);
	// printf("%s\n", buff);
	line = ft_strjoin(line, buff);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*s;

	printf("%zu\n", ft_strlen(""));
	fd = open("test.txt", O_RDONLY);
	s = gnl(fd);
	free(s);
	close(fd);
}
