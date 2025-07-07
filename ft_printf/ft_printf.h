/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuharada <yuharada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:08:47 by yuharada          #+#    #+#             */
/*   Updated: 2025/07/05 18:48:23 by yuharada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		output_c(va_list	*ap);
int		output_s(va_list	*ap);
int		output_p(va_list	*ap);
int		output_d_i(va_list	*ap);
int		output_u(va_list	*ap);
int		output_x(va_list	*ap);
int		output_large_x(va_list	*ap);
int		output_per(va_list	*ap);

#endif
