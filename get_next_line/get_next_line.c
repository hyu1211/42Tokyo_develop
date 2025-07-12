/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:18:20 by yuharada          #+#    #+#             */
/*   Updated: 2025/07/12 16:18:20 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strmerge(char *tmp, char *save, char *buffer)
{
	int	tmp_num;
	int	save_num;
	int	buffer_num;

	tmp_num = 0;
	save_num = 0;
	buffer_num = 0;
	if (save)
	{
		while (save[save_num])
		{
			tmp[tmp_num] = save[save_num];
			tmp_num++;
			save_num++;
		}
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

char	*get_next_line(int fd)
{
	int			save_len;
	int			read_len;
	char		*buffer;
	char		*tmp;
	static char	*save;
	char		*n;
	char		*new_save;
	char		*line;
	char		*last_line;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));//一次バッファの確保
	if (buffer == NULL)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	while (!save || !ft_strchr(save, '\n'))//saveがないまたは改行がないとき、read、結合、格納を進める
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len == 0)//読み切ったとき
		{
			free (buffer);
			if (save == NULL || *save == '\0')//何もないときNULLを返す
			{
				free (save);
				save = NULL;
				return (NULL);
			}
			last_line = save;
			save = NULL;//saveをNULLにせずにmainでfreeすると、存在しないメモリを指すポインタができてしまう
			return (last_line);
		}
		else if (read_len == -1)//readでエラー
		{
			perror ("read");
			free (save);
			free (buffer);
			save = NULL;
			return(NULL);
		}
		buffer[read_len] = '\0';
		save_len = ft_strlen_null(save);
		tmp = (char *)malloc(sizeof(char) * (save_len + read_len + 1));
		if (tmp == NULL)
		{
			free (save);
			save = NULL;
			return (NULL);
		}
		ft_strmerge(tmp, save, buffer);
		free (save);
		save = tmp;
	}
	free (buffer);
	if (save == NULL)
  		return (NULL);
	n = ft_strchr(save, '\n');
	if (n != NULL)
	{
  	line = ft_trim_aftern(save, n);
	if (line == NULL)
	{
		free (save);
		save = NULL;
		return (NULL);
	}
	new_save = ft_trim_beforen(save, n);
	if (new_save == NULL)
	{
		free (save);
		free (line);
		save = NULL;
		return (NULL);
	}
  	free(save);
	save = new_save;
	return (line);
	}
	else
	{
  	  line = save;
 	   save = NULL;
  	  return (line);
	}
}

