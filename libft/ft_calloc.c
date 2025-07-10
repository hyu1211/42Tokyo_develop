/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:42:03 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/11 16:54:40 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//メモリを確保し、ゼロで初期化

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

// int	main(void)
// {
// 	int	*arr;
// 	int	i;

// 	arr = (int *)ft_calloc(5, sizeof(int));
// 	if (!arr)
// 		return (1);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d\n", arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return (0);
// }
