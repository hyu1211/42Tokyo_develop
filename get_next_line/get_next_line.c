#include "get_next_line.h"

char *get_next_line(int fd)
{
	int			total_len;
	int			read_len;
    char		buffer[BUFFER_SIZE];
    char		*tmp;
	static char	*line;

	total_len = 0;
	tmp = NULL;
	while (ft_strchr(buffer, '\n') == NULL)
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len == 0)
			return (0);
		else if (read_len == -1)
		{
			perror("read");
			return(NULL);
		}
		total_len += read_len;
		line = (char *)malloc(sizeof(char) * total_len);
		if (line == NULL)
			return (NULL);
		ft_dup(line, tmp, buffer);\\lineにtmpとbufferを結合させたものを格納する
		tmp = line;
	}
	//readで\nが見つかった時の処理、
	//静的関数に読み込んだ情報を保持する処理
	//free処理
}

int main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 1)
		fd = 0;
	else if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
		{
			perror ("open");
			return (1);
		}
	}
	else
    {
		ft_putstr_fd("%s\n", "Error: Invalid number of arguments\n", 2);
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_putstr_fd(line, 1);
		free (line);
	}
	if (fd > 2)
		close (fd);
	return (0);
}