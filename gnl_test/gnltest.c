#include "get_next_line.h"

char	*first(int fd)
{

}

char *next_line(int fd)
{
	char	*buff;
	char	*next;
	int num_read;

	buff = NULL;
	if (!buff)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
	}
	num_read = read(fd, buff, BUFFER_SIZE);
	next = ft_strchr(buff, '\n');
	if (!next || num_read == -1)
		return (NULL);
	// free(buff);
	// printf("%s\n", next);
	*next = '\0';
	return (next + 1);
}

char *gnl(int fd)
{
	static char *line;
	char *find_next;
	if (!line)
	{
		line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!line)
			return (NULL);
	}
	find_next = next_line(fd);
	line = 
	if (!ft_strlen(line))
	{
		line = find_next;
	}
	else
	{
		line = ft_strjoin(line, find_next);
	}
	// line[0] = '\0';
	printf("%s\n", line);
	return (NULL);
}

int main(void)
{
	int fd;
	char *s;

	fd = open("test.txt", O_RDONLY);
	s = gnl(fd);
	free(s);
}