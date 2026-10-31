/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguiber <jeguiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:48:16 by jeguiber          #+#    #+#             */
/*   Updated: 2026/10/31 04:09:23 by jeguiber         ###   ########.fr       */
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

	if (!str)
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

int	ft_putptr(void *ptr)
{
	int	len;
	int	tmp;

	len = 0;
	tmp = 0;
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	tmp = ft_puthexa((unsigned long) ptr, 'x');
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	c = ft_putchar('\t');

// 	printf("\n");
// 	int	di = ft_putnbr(-3456789L);

// 	printf("\n");
// 	int	s = ft_putstr("qwertyu");

// 	printf("\n");
// 	int	h = ft_puthexa(23456789U, 'X');

// 	printf("\n");
// 	int	p = ft_putptr("Test");

// 	printf("\n\nchr_len : %d - $c", c);
// 	printf("\nnbr_len : %d - $d", di);
// 	printf("\nstr_len : %d - $s", s);
// 	printf("\nhex_len : %d - $h", h);
// 	printf("\nptr_len : %d - $p", p);
// 	printf("\n");
// 	return (0);
// }
