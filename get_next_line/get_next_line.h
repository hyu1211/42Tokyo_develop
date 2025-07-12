/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:12:24 by yuharada          #+#    #+#             */
/*   Updated: 2025/07/12 16:12:24 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_buflist
{
	int					read_len;
	int					is_n;
	char				*buffer;
	struct s_buflist	*next_buf;
}				t_buflist;

typedef struct s_fdlist
{
	int				fd;
	char			*remaining_data;
	struct s_fdlist	next_fd;
}				t_fdlist;

char			*get_next_line(int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strchr(char const *str, int c);
int				ft_strlen_null(char *str);
char			*ft_strmerge(char *tmp, char *save, char *buffer);
char			*ft_trim_aftern(char *str, char *sep);
char			*ft_trim_beforen(char *str, char *sep);
struct t_fdlist	*fd_check(t_fdlist fdlist, int fd);

#endif