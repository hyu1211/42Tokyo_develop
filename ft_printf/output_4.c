/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:35:13 by yuharada          #+#    #+#             */
/*   Updated: 2025/07/05 18:35:44 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_hex_large(unsigned int hexnum)
{
	unsigned int	digit;
	char			c;

	digit = 0;
	if (hexnum >= 16)
	{
		digit += putnbr_hex_large(hexnum / 16);
	}
	c = "0123456789ABCDEF"[hexnum % 16];
	write(1, &c, 1);
	return (digit + 1);
}

int	output_large_x(va_list	*ap)
{
	unsigned int	hexnum;

	if (!ap)
		return (-1);
	hexnum = va_arg(*ap, unsigned int);
	return (putnbr_hex_large(hexnum));
}

int	output_per(va_list	*ap)
{
	(void)ap;
	return (write(1, "%", 1));
}
