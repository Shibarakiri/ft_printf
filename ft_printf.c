/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguiber <jeguiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 01:46:30 by jeguiber          #+#    #+#             */
/*   Updated: 2026/10/31 04:04:47 by jeguiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkif(va_list args, const char c)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		tmp;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			tmp = ft_checkif(args, *(++str));
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		else
		{
			if (write(1, str, 1) == -1)
				return (-1);
			len++;
		}
		str++;
	}
	va_end(args);
	return (len);
}
