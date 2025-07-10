/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:50:25 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/11 18:24:14 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char const *src)
{
	char	*dest;
	int		i;

	dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <unistd.h>

// int	main(void)
// {
// 	char	src[] = "42Tokyo";
// 	char	*arr = ft_strdup(src);

// 	write(1, arr, ft_strlen(arr));
// 	write(1, "\n", 1);
// 	write(1, src, ft_strlen(src));
// 	write(1, "\n", 1);
// 	free (arr);
// 	return (0);
// }
