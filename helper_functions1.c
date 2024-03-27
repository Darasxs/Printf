/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:33:53 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/03/27 16:32:27 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
int	ft_print_string(char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int i)
{
	int		length;
	char	c;

	length = 0;
	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
		length++;
	}
	if (i < 10)
	{
		c = i + '0';
		write(1, &c, 1);
		length++;
	}
	length += ft_print_nbr(i / 10);
	c = i % 10 + '0';
	write(1, &c, 1);
	return (length);
}

int	ft_print_unsigned(int i)
{
	int		length;
	char	c;

	length = 0;
	if (i < 10)
	{
		c = i + '0';
		write(1, &c, 1);
		length++;
	}
	length += ft_print_unsigned(i / 10);
	c = i % 10 + '0';
	write(1, &c, 1);
	return (length);
}
