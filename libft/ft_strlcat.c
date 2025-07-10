/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:13:24 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/11 16:41:11 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//安全に（サイズを考慮して）文字列を連結

#include <stdio.h>

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = 0;
	s_len = 0;
	i = 0;
	while (dest[d_len] && d_len < size)
		d_len++;
	while (src[s_len])
		s_len++;
	if (size <= d_len)
		return (size + s_len);
	while ((d_len + i < size - 1) && src[i])
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char			dest[] = "1234";
// 	char			src[] = "567";
// 	unsigned int	n;

// 	n = ft_strlcat(src, dest, 2);
// 	printf("%s\n", dest);
// 	printf("%u\n", n);
// 	return (0);
// }
