/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:32:00 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/11 18:24:53 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//2つの文字列を連結して新しい文字列を作成

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*dest;
	int		i;
	int		j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char	s1[] = "Hello, ";
// 	char	s2[] = "42Tokyo";

// 	printf("%s\n", ft_strjoin(s1, s2));
// 	return (0);
// }
