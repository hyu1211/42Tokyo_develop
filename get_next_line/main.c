#include "get_next_line.h"

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
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
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