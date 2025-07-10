/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:26:32 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/11 18:18:35 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//2つの文字列をn文字まで比較

#include <stdio.h>

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n))
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0')
			break ;
		s1++;
		s2++;
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char s1[] = "123456";
// 	char s2[] = "123";

// 	printf("%d\n", ft_strncmp(s1, s2, 6));
// 	return (0);
// }
