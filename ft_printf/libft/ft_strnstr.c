/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:26:52 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/11 17:04:09 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check(const char *str, const char *dest)
{
	while (*dest)
	{
		if (*str != *dest)
			return (0);
		str++;
		dest++;
	}
	return (1);
}

char	*ft_strnstr(const char *src, const char *dest, size_t n)
{
	size_t		dest_len;
	size_t		i;

	dest_len = 0;
	i = 0;
	while (dest[dest_len])
		dest_len++;
	if (dest_len == 0)
		return ((char *)src);
	while (*src && i + dest_len <= n)
	{
		if ((*src == dest[0]) && ft_check(src, dest))
			return ((char *)src);
		src++;
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char src[] = "123abc456abd456";
// 	char dest[] = "abd";

// 	printf("%s\n", ft_strnstr(src, dest, 13));
// 	return (0);
// }
