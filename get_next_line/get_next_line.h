#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

#define BUFFER_SIZE 1024

char    *get_next_line(int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(char const *str, int c);
int 	ft_strlen_null(char *str);
char    *ft_strmerge(char *tmp, char *save, char *buffer);
char    *ft_trim_aftern(char *str, char *sep);
char	*ft_trim_beforen(char *str, char *sep);

#endif