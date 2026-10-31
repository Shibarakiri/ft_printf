/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguiber <jeguiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:55:35 by jeguiber          #+#    #+#             */
/*   Updated: 2026/10/31 03:58:34 by jeguiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putptr(void *ptr);
int	ft_puthexa(unsigned long nb, char c);
int	ft_putnbr(long n);
int	ft_putstr(char *str);
int	ft_putchar(char c);
#endif
