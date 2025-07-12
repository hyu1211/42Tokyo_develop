/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:15:47 by yuharada          #+#    #+#             */
/*   Updated: 2025/07/12 16:15:47 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}

char	*ft_strchr(char const *str, int c)
{
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

int	ft_strlen_null(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_trim_aftern(char *str, char *sep)
{
	int		dif_len;
	int		num;
	char	*newstr;

	num = 0;
	dif_len = ft_strlen_null(str) - ft_strlen_null(sep) + 1;
	newstr = (char *)malloc(sizeof(char) * dif_len + 1);
	if (newstr == NULL)
		return (NULL);
	while (num < dif_len)
	{
		newstr[num] = str[num];
		num++;
	}
	newstr[num] = '\0';
	return (newstr);
}

char	*ft_trim_beforen(char *str, char *sep)
{
	int		remaining_len;
	int		num;
	char	*newstr;

	num = 0;
	remaining_len = ft_strlen_null(str) - (sep - str) - 1;
	if (remaining_len <= 0)
	{
		newstr = (char *)malloc(sizeof(char) * 1);
		if (newstr == NULL)
			return (NULL);
		newstr[0] = '\0';
		return (newstr);
	}
	newstr = (char *)malloc(sizeof(char) * (remaining_len + 1));
	if (newstr == NULL)
		return (NULL);
	while (num < remaining_len)
	{
		newstr[num] = str[(sep - str) + 1 + num];
		num++;
	}
	newstr[num] = '\0';
	return (newstr);
}
