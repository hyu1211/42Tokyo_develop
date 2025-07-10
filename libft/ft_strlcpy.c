/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:46:59 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/24 15:44:13 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//安全に（サイズを考慮して）文字列をコピ

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (src[a])
		a++;
	if (size == 0)
		return (a);
	while (src[b] && b < size - 1)
	{
		dest[b] = src[b];
		b++;
	}
	dest[b] = '\0';
	return (a);
}

// int	main(void)
// {
// 	char	src[] = "42Tokyo";
// 	char	dest[10];

// 	printf("%zu\n", ft_strlcpy(dest, src, 5));
// 	printf("%s\n", dest);
// 	return (0);
// }
