/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:44:52 by yuharada          #+#    #+#             */
/*   Updated: 2025/07/05 18:46:07 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_positive_nbr(int n, int fd)
{
	int		count;
	int		temp_result;
	char	c;

	count = 0;
	if (n >= 10)
	{
		temp_result = ft_put_positive_nbr(n / 10, fd);
		if (temp_result == -1)
			return (-1);
		count += temp_result;
	}
	c = (n % 10) + '0';
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putnbr_fd_counted(int n, int fd)
{
	int	count;
	int	temp_result;

	if (n == INT_MIN)
	{
		if (write(fd, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	count = 0;
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		count = 1;
		n = -n;
	}
	temp_result = ft_put_positive_nbr(n, fd);
	if (temp_result == -1)
		return (-1);
	return (count + temp_result);
}

int	output_d_i(va_list *ap)
{
	int	num;

	if (!ap)
		return (-1);
	num = va_arg(*ap, int);
	return (ft_putnbr_fd_counted(num, 1));
}

// int	ft_putnbr_fd_counted(int n, int fd)
// {
// 	int		count;
// 	int		temp_result;
// 	char	c;

// 	count = 0;
// 	if (n == -2147483648)
// 	{
// 		if (write(fd, "-2147483648", 11) == -1)
// 			return (-1);
// 		return (11);
// 	}
// 	if (n < 0)
// 	{
// 		if (write(fd, "-", 1) == -1)
// 			return (-1);
// 		count = 1;
// 		n = -n;
// 	}
// 	if (n >= 10)
// 	{
// 		temp_result = ft_putnbr_fd_counted(n / 10, fd);
// 		if (temp_result == -1)
// 			return (-1);
// 		count += temp_result;
// 	}
// 	c = (n % 10) + '0';
// 	if (write(fd, &c, 1) == -1)
// 		return (-1);
// 	count++;
// 	return (count);
// }
