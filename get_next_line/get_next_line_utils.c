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

char    *ft_strmerge(char *tmp, char *save, char *buffer)
{
    int	tmp_num;
	int	save_num;
	int	buffer_num;

	tmp_num = 0;
	save_num = 0;
	buffer_num = 0;
    while (save[save_num])
    {
        tmp[tmp_num] = save[save_num];
		tmp_num++;
		save_num++;
    }
	while (buffer[buffer_num])
	{
		tmp[tmp_num] = buffer[buffer_num];
		tmp_num++;
		buffer_num++;
	}
	tmp[tmp_num] = '\0';
	return (tmp);
}

char    *ft_trim_aftern(char *str, char *sep)
{
    int     dif_len;
    int     num;
    char    *newstr;

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
	int		sep_len;
	int		str_len;
	int		num;
	char	*newstr;

	num = 0;
	str_len = ft_strlen_null(str);
	sep_len = ft_strlen_null(sep) - 1;
	newstr = (char *)malloc(sizeof(char) * (sep_len + 1));
	if (newstr == NULL)
		return (NULL);
	while(num < sep_len)
	{
		newstr[num] = str[num + str_len - sep_len];
		num++;
	}
	newstr[num] = '\0';
	return (newstr);
}
