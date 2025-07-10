/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:16:59 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/11 16:55:41 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1 = buf1;
	const unsigned char	*ptr2 = buf2;

	i = 0;
	while (i < n)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char buf1[] = "123458";
// 	char buf2[] = "123457";

// 	printf("%d\n", memcmp(buf1, buf2, 6));
// 	return (0);
// }
