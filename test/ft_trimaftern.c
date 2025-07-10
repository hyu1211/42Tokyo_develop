#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
    char    a[] = "0123456789";
    char    *b;
    char    *str;

    b = a + 5;
    str = ft_trim_aftern(a, b);
    printf("%s\n",str);
    free (str);
    return (0);
}
