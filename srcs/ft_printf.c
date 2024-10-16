/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:10:01 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/16 13:55:46 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		val;
	int		i;

	if (input == NULL)
		return (-1);
	va_start(args, input);
	val = ft_strlen(input);
	i = 0;
	while (input[i])
	{
		if (is_corrupted(&input[i]))
		{
			val = -1;
			break ;
		}
		if (is_conversion(&input[i]))
			val += print_conversion(&input[i++], args) - 2;
		else
			ft_putchar((char)input[i]);
		i++;
	}
	va_end(args);
	return (val);
}

// int	main(void)
// {
// 	printf("\n%d\n", printf("oul%s    %", "caca"));
// 	write(1, "\n", 1);
// 	printf("\n%d\n", ft_printf("oul%s    %", "caca"));
// }
