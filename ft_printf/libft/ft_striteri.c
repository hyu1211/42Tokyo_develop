/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:31:00 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/11 17:32:23 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

// void	to_upper(unsigned int i, char *c)
// {
// 	(void)i;
// 	while (*c)
// 	{
// 		if (*c >= 'a' && *c <= 'z')
// 			*c -= 32;
// 		c++;
// 	}
// }

// int	main(void)
// {
// 	char	s[] = "42Tokyo";

// 	ft_striteri(s, to_upper);
// 	printf("%s\n", s);
// 	return (0);
// }
