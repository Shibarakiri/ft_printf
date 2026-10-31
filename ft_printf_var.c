/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguiber <jeguiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 01:48:16 by jeguiber          #+#    #+#             */
/*   Updated: 2026/10/31 03:13:24 by jeguiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!*str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (*str)
	{
		if (write(1, str, 1) == -1)
			return (-1);
		i++;
		str++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int		len;
	int		tmp;
	long	nb;

	len = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len += 1;
		n = -n;
	}
	nb = n % 10 + '0';
	if (n >= 10)
	{
		tmp = ft_putnbr(n / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &nb, 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_puthexa(unsigned long nb, char c)
{
	int		i;
	int		len;
	int		tmp;
	char	*stock;

	i = 0;
	len = 0;
	if (c == 'x')
		stock = "0123456789abcdef";
	else
		stock = "0123456789ABCDEF";
	if (nb >= 16)
	{
		tmp = ft_puthexa(nb / 16, c);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	i = nb % 16;
	if (write(1, &stock[i], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	a = ft_putnbr(-3456789L);

// 	write(1, "\n", 1);
// 	int	b = ft_putstr("qwertyu");

// 	write(1, "\n", 1);
// 	int	c = ft_puthexa(23456789U, 'X');

// 	printf("\n\nnbr_len : %d\nstr_len : %d\nhexa_len : %d\n", a, b, c);
// 	return (0);
// }
