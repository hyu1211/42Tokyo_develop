/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:34:50 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/24 15:59:21 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//整数を文字列に変換

#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <limits.h>

static int	count_nbr(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	nbr = n;
	len = count_nbr(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (--len >= 0 && str[len] != '-')
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

// int	main(void)
// {
// 	char	*dest;
// 	dest = ft_itoa(2147483647);
// 	printf("%s", dest);
// 	free (dest);
// 	return (0);
// }
