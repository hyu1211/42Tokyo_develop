#include <stdio.h>

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

int	main(void)
{
	char a[10];
	char b[] = "123456";
	char c[] = "789";
	char *str;

	str = ft_strmerge(a, b, c);
	printf("%s\n", str);
	return (0);
}