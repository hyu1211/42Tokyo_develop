/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:26:16 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/11 17:37:42 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>

static int	ft_word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t len)
{
	size_t	i;
	char	*res;

	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static void	*ft_free_all(char **arr, int i)
{
	while (--i >= 0)
		free(arr[i]);
	free(arr);
	return (NULL);
}

static char	**ft_split_helper(char **res, const char *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			res[i] = ft_strndup(s, len);
			if (!res[i])
				return (ft_free_all(res, i));
			i++;
			s += len;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!res)
		return (NULL);
	return (ft_split_helper(res, s, c));
}

// int	main(void)
// {
// 	char	s[] = "12301234501201";
// 	char	**dest = ft_split(s, '0');
// 	int		i;

// 	i = 0;
// 	while (dest[i])
// 	{
// 		printf("%s\n", dest[i]);
// 		i++;
// 	}
// 	free (dest);
// 	return (0);
// }
