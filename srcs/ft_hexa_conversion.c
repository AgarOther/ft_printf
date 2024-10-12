/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:19:16 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/12 10:19:17 by scraeyme         ###   ########.fr       */
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
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	return (str);
}

static char	*get_hex_str(char *hex, int n, int val, char *str)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		val++;
		ft_putchar('-');
	}
	while (n > 0)
	{
		str[i] = (hex[n % 16]);
		n /= 16;
		i++;
	}
	str[i] = 0;
	str = ft_revstr(str);
	return (str);
}

int	ft_print_hexadecimal(int n, int is_upper)
{
	char	*hex;
	char	*str;
	int		val;

	hex = ft_strdup("0123456789ABCDEF", is_upper);
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	val = ft_intlen(n);
	str = malloc(val + 1);
	if (!str)
		return (-1);
	if (!is_upper)
		hex = ft_strlower(hex);
	str = get_hex_str(hex, n, val, str);
	free(hex);
	ft_putstr(str);
	val = ft_strlen(str) + (n < 0);
	free(str);
	return (val);
}
