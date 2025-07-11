#include "get_next_line.h"

char *get_next_line(int fd)
{
	int			save_len;
	int			read_len;
    char		buffer[BUFFER_SIZE + 1];
    char		*tmp;
	static char	*save;
	char		*n;
	char		*new_save;
	char		*line;
	char		*last_line;

	while (!save || (save && !ft_strchr(save, '\n')))
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len == 0)
		{
			if (save == NULL || *save == '\0')
			{
				free (save);
				save = NULL;
				return (NULL);
			}
			last_line = save;
			save = NULL;
			return (last_line);
		}
		else if (read_len == -1)
		{
			perror ("read");
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
		ft_strmerge(tmp, save, buffer);//save = tmp + buffer + \0
		free (save);
		save = tmp;
	}
	if (save == NULL)
  		return (NULL);
	n = ft_strchr(save, '\n');
	if (n != NULL)
	{
  	  line = ft_trim_aftern(save, n);//NULLチェック必要？
  	  new_save = ft_trim_beforen(save, n);//ここも
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

