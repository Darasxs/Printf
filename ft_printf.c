/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:02:50 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/03/26 19:10:30 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checker(char *s, va_list arg)
{
	int len;

	len = 0;
	va_start(arg, s);
	while (*s)
	{
		if (*s == 'c')
			len += ft_print_char(va_arg(arg, int));
		else if (*s == '%')
			len += ft_print_percent();
		else if (*s == 's')
			len += ft_print_string(va_arg(arg, char *));
		else if (*s == 'd' || *s == 'i')
			len += ft_print_nbr(va_arg(arg, int));
		else if (*s == 'u')
			len += (ft_unsigned());
		//else if (*s == 'x')
		//	return (ft_hexa());
		//else if (*s == 'X')
		//	return (ft_hexa());
		//else if (*s == 'p')
		//	len += ft_print_pointer(va_arg(arg, void *));
		s++;
	}
	va_end(arg);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		final;

	final = 0;
	if (str == NULL)
		return (-1);
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			final += ft_checker(str , va);
		}
		else
			final += write(1, str, 1);
		str++;
	}
	va_end(va);
	return (final);
}

// i have to handle these conversions: cspdiuxX%
//• %p The void * pointer argument has to be printed in hexadecimal format.
//• %u Prints an unsigned decimal (base 10) number.
//• %x Prints a number in hexadecimal (base 16) lowercase format.
//• %X Prints a number in hexadecimal (base 16) uppercase format.