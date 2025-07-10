/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:10:04 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/11 16:50:02 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//文字列内である文字が最後に現れる場所を探す

#include <stdlib.h>
#include <stdio.h>

char	*ft_strrchr(char *str, int c)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if ((char)c == '\0')
		return (str + len);
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return (str + len);
		len--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char str[] = "1231231234";
// 	printf("%s\n", ft_strrchr(str, '2'));
// 	return (0);
// }
