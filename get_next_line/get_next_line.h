#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#define BUFFER_SIZE 1024

char    *get_next_line(int fd);
void    ft_putstr_fd(chat *s, int fd)

#endif