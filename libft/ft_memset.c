/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:29:19 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/11 15:31:11 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//メモリを特定の文字で埋める

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	dest = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	int const	s[] = {1, 2, 3, 4, 5, 6};

// 	printf("%s\n", ft_memset(s, 0, 3));
// 	return (0);
// }
