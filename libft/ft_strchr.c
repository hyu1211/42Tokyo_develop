/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:59:38 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/11 16:43:11 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//文字列内である文字が最初に現れる場所を探す

#include <stdlib.h>
#include <stdio.h>

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

// int	main(void)
// {
// 	char str[] = "123456123";
// 	printf("%s\n", ft_strchr(str, '2'));
// 	return (0);
// }
