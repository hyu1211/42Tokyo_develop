/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:32:46 by yuharada          #+#    #+#             */
/*   Updated: 2025/05/26 18:49:59 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_unsigned(unsigned int num)
{
	unsigned int	digit;
	char			c;

	digit = 0;
	if (num >= 10)
	{
		digit += putnbr_unsigned(num / 10);
	}
	c = "0123456789"[num % 10];
	write(1, &c, 1);
	return (digit + 1);
}

int	output_u(va_list	*ap)
{
	unsigned int	num;

	if (!ap)
		return (write(1, "0", 1));
	num = va_arg(*ap, unsigned int);
	return (putnbr_unsigned(num));
}

int	putnbr_hex_small(unsigned int hexnum)
{
	unsigned int	digit;
	char			c;

	digit = 0;
	if (hexnum >= 16)
	{
		digit += putnbr_hex_small(hexnum / 16);
	}
	c = "0123456789abcdef"[hexnum % 16];
	write(1, &c, 1);
	return (digit + 1);
}

int	output_x(va_list	*ap)
{
	unsigned int	hexnum;

	if (!ap)
		return (-1);
	hexnum = va_arg(*ap, unsigned int);
	return (putnbr_hex_small(hexnum));
}
