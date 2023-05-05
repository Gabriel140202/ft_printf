/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancis <gfrancis@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:00:02 by gfrancis          #+#    #+#             */
/*   Updated: 2023/05/05 10:11:02 by gfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	typeargs(va_list args, const char *str, long long i)
{
	if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str[i + 1] == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (str[i + 1] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (str[i + 1] == 'u')
		return (ft_putunnbr(va_arg(args, unsigned int)));
	else if (str[i + 1] == 'x')
		return (ft_putnbr_hx(va_arg(args, unsigned int), 0));
	else if (str[i + 1] == 'X')
		return (ft_putnbr_hx(va_arg(args, unsigned int), 1));
	else if (str[i + 1] == '%')
		return (ft_putchar('%'));
	else if (str[i + 1] == 'p')
		return (ft_putstr("0x")
			+ ft_putptr(va_arg(args, unsigned long)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	long long	i;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += typeargs(args, str, i);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}		
	va_end(args);
	return (i);
}
