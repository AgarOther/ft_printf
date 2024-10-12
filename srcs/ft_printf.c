/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:10:01 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/12 19:35:01 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		val;
	int		i;

	if (input == NULL || is_corrupted(input))
		return (-1);
	va_start(args, input);
	val = ft_strlen(input);
	i = 0;
	while (input[i])
	{
		if (is_conversion(&input[i]) && input[i + 1])
		{
			val += print_conversion(&input[i], args) - 2;
			i++;
		}
		else
			ft_putchar((char)input[i]);
		i++;
	}
	va_end(args);
	return (val);
}
