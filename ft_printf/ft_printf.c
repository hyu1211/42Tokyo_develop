/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:51:22 by yuharada          #+#    #+#             */
/*   Updated: 2025/07/05 18:50:47 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	spec_sort(const char *spec, va_list *ap)
{
	if (*spec == 'c')
		return (output_c(ap));
	if (*spec == 's')
		return (output_s(ap));
	if (*spec == 'p')
		return (output_p(ap));
	if (*spec == 'd' || *spec == 'i')
		return (output_d_i(ap));
	if (*spec == 'u')
		return (output_u(ap));
	if (*spec == 'x')
		return (output_x(ap));
	if (*spec == 'X')
		return (output_large_x(ap));
	if (*spec == '%')
		return (output_per(ap));
	else
		return (-1);
}

static int	process_chunk(const char **str, va_list *args)
{
	int	len;

	if (**str == '%' && *(*str + 1))
	{
		(*str)++;
		len = spec_sort(*str, args);
		if (len == -1)
			return (-1);
		(*str)++;
		return (len);
	}
	else
	{
		if (write(1, *str, 1) == -1)
			return (-1);
		(*str)++;
		return (1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		total_len;
	int		chunk_len;

	if (!str)
		return (-1);
	va_start(args, str);
	total_len = 0;
	while (*str)
	{
		chunk_len = process_chunk(&str, &args);
		if (chunk_len == -1)
		{
			va_end(args);
			return (-1);
		}
		total_len += chunk_len;
	}
	va_end(args);
	return (total_len);
}

// int	ft_printf(const char *str, ...)
// {
// 	va_list	args;
// 	int		spec_len;
// 	int		total_len;

// 	if (!str)
// 		return (-1);
// 	va_start(args, str);
// 	total_len = 0;
// 	while (*str)
// 	{
// 		if (*str == '%' && (*(str + 1)))
// 		{
// 			str++;
// 			spec_len = spec_sort(str, &args);
// 			if (spec_len < 0)
// 			{
// 				va_end(args);
// 				return (-1);
// 			}
// 			total_len += spec_len;
// 			str++;
// 		}
// 		else
// 		{
// 			write(1, str, 1);
// 			total_len++;
// 			str++;
// 		}
// 	}
// 	va_end(args);
// 	return (total_len);
// }

// int	main(void)
// {
// 	char	c = 'a';
// 	char 	str[] = "42Tokyo";
// 	char	emp[] = "";
// 	int		num1 = 12345;
// 	unsigned int		num2 = 12345;
// 	unsigned int		num3 = 0x123a;

// 	ft_printf("%c %c\n", c, 64);
// 	printf("%c %c\n", c, 64);

// 	ft_printf("%s %s\n", str, emp);
// 	printf("%s %s\n", str, emp);

// 	ft_printf("%p %p\n", str, NULL);
// 	printf("%p %p\n", str, NULL);

// 	ft_printf("%d %d\n", num1, 0);
// 	printf("%d %d\n", num1, 0);

// 	ft_printf("%i %i\n", num1, 0);
// 	printf("%i %i\n", num1, 0);

// 	ft_printf("%u %u\n", num2, 0);
// 	printf("%u %u\n", num2, 0);

// 	ft_printf("%x %x\n", num3, 0);
// 	printf("%x %x\n", num3, 0);

// 	ft_printf("%X %X\n", num3, 0);
// 	printf("%X %X\n", num3, 0);

// 	ft_printf("%%\n");
// 	printf("%%\n");

// 	ft_printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%", \
// 			c, str, str, num1, num1, num2, num3, num3);
// }
