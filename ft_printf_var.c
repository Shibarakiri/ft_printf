/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguiber <jeguiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 01:48:16 by jeguiber          #+#    #+#             */
/*   Updated: 2026/10/31 02:48:14 by jeguiber         ###   ########.fr       */
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

// #include <stdio.h>

// int	main(void)
// {
// 	int	a = ft_putnbr(-3456789L);

// 	write(1, "\n", 1);
// 	int	b = ft_putstr("qwertyu");

// 	printf("\n\nnbr_len : %d\nstr_len : %d\n", a, b);
// 	return (0);
// }
