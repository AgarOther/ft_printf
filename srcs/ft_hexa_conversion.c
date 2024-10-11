/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:19:16 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/11 22:47:56 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_revstr(char *str)
{
	int		i;
	int		len;
	char	temp;
	
	i = 0;
	len = ft_strlen(str);
	while (i < len - 1)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	return (str);
}

int	ft_print_hexadecimal(int n, int is_upper)
{
	char	*hex;
	int		val;

	hex = ft_strdup("0123456789ABCDEF");
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	val = ft_intlen(n);
	if (!is_upper)
		hex = ft_strlower(hex);
	if (n < 0)
	{
		n *= -1;
		val++;
		ft_putchar('-');
	}
	while (n > 0)
	{
		ft_putchar(hex[n % 16]);
		n /= 16;
	}
	free(hex);
	return (val);
}
