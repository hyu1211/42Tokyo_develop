/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:08:38 by yuharada          #+#    #+#             */
/*   Updated: 2025/07/05 18:47:12 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_c(va_list	*ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	return (write(1, &c, 1));
}

int	output_s(va_list	*ap)
{
	int		str_len;
	int		write_check;
	char	*str;

	str = va_arg(*ap, char *);
	str_len = 0;
	write_check = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write_check = write(1, str, 1);
		if (write_check <= 0)
			return (-1);
		str_len += write_check;
		str++;
	}
	return (str_len);
}

// int	output_p(va_list *ap)
// {
// 	uintptr_t	addr;
// 	void		*ptr;
// 	int			bit;
// 	int			started;
// 	char		c;
// 	int			len;

// 	ptr = va_arg(*ap, void *);
// 	if (!ptr)
// 	{
// 		write(1, "(nil)", 5);
// 		return (5);
// 	}
// 	addr = (uintptr_t)ptr;
// 	write(1, "0x", 2);
// 	len = 2;
// 	started = 0;
// 	if (sizeof(addr) == 8)
// 	{
// 		bit = 60;
// 		while (bit >= 0)
// 		{
// 			c = "0123456789abcdef"[(addr >> bit) & 0xF];
// 			if (c != '0' || started)
// 			{
// 				write(1, &c, 1);
// 				len++;
// 				started = 1;
// 			}
// 			bit -= 4;
// 		}
// 		return (len);
// 	}
// 	if (sizeof(addr) == 4)
// 	{
// 		bit = 28;
// 		while (bit >= 0)
// 		{
// 			c = "0123456789abcdef"[addr >> bit & 0xF];
// 			if (c != '0' || started)
// 			{
// 				write(1, &c, 1);
// 				len++;
// 				started = 1;
// 			}
// 			bit -= 4;
// 		}
// 		return (len);
// 	}
// 	return (-1);
// }

static int	ft_puthex_p(uintptr_t addr)
{
	int		len;
	int		temp_len;
	char	c;

	len = 0;
	if (addr >= 16)
	{
		temp_len = ft_puthex_p(addr / 16);
		if (temp_len == -1)
			return (-1);
		len += temp_len;
	}
	c = "0123456789abcdef"[addr % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len + 1);
}

int	output_p(va_list *ap)
{
	uintptr_t	addr;
	int			len;
	int			temp_len;

	addr = (uintptr_t)va_arg(*ap, void *);
	if (addr == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	len = 2;
	temp_len = ft_puthex_p(addr);
	if (temp_len == -1)
		return (-1);
	return (len + temp_len);
}
