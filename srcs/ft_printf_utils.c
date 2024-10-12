/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:15:43 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/11 22:49:05 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	get_converter(char *str)
{
	return (str[1]);
}

int	is_conversion(char *c)
{
	if (c[0] != '%')
		return (0);
	return (c[1] == 'c' || c[1] == 's' || c[1] == 'p' || c[1] == 'd'
		|| c[1] == 'i' || c[1] == 'u' || c[1] == 'x' || c[1] == 'X'
		|| c[1] == '%');
}

int	count_conversions(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i + 1])
	{
		if (str[i] == '%' && is_conversion(&str[i]))
			count++;
		i++;
	}
	return (count);
}

int	print_conversion(char *str, va_list arg)
{
	char	c;
	int		val;

	c = get_converter(str);
	val = 0;
	if (c == 'c')
		val += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		val += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		(void)c; // Hexa conversion
	else if (c == 'd') // Similar to i?
		val += ft_putnbr(va_arg(arg, int));
	else if (c == 'i')
		val += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		val += ft_putnbr(va_arg(arg, unsigned int));
	else if (c == 'x')
		val += ft_print_hexadecimal(va_arg(arg, int), 0);
	else if (c == 'X')
		val += ft_print_hexadecimal(va_arg(arg, int), 1);
	else if (c == '%')
		val += ft_putchar('%');
	return (val);
}

int	is_corrupted(char *str)
{
	int	i;

	i = 0;
	if (!str || (ft_strlen(str) == 1 && str[0] == '%'))
		return (1);
	while (str[i + 1])
	{
		if (!is_conversion(&str[i]) && str[i] == '%')
			return (1);
		i++;
	}
	return (0);
}