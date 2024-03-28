/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:33:46 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/03/28 17:39:22 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nbr, const char *base)
{
	int	length;

	length = 0;
	if (nbr < 16)
	{
		write(1, &base[nbr % 16], 1);
		return (1);
	}
	length += ft_print_hex(nbr / 16, base);
	write(1, &base[nbr % 16], 1);
	return (length);
}
int	ft_print_pointer(unsigned long long i, char *base)
{
	int length;

	length = 0;
	if (i == 0)
	{
		write(1, "0x", 3);
		return (3);
	}
	length += ft_print_pointer(i / 16, base);
	write(1, &base[i % 16], 1);

	return (length);
}
