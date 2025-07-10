/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:06:43 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/10 21:00:50 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//文字列の各文字に関数を適用し、新しい文字列を作成

#include <stdio.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int					i;
	unsigned int		j;
	char				*dest;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	j = 0;
	while (s[j])
	{
		dest[j] = f(j, s[j]);
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

// char	to_upper(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }

// int	main(void)
// {
// 	char const	s[] = "42Tokyo";

// 	printf("%s\n", ft_strmapi(s, to_upper));
// 	return (0);
// }
