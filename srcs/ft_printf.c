/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:10:01 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/12 11:53:36 by scraeyme         ###   ########.fr       */
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

/*int	main(void)
{
	char *ptr;
 	printf("\nPrinted: %d\n", ft_printf("--- FT_PRINTF ---\n%p", ptr));
	printf("\nPrinted: %d\n", printf("---   PRINTF  ---\n%p", ptr));
	// ft_printf("--------------------------------------------------------------");
	// printf("\nPrinted: %d\n", ft_printf("--- FT_PRINTF ---\n%dx", 154564567));
	// printf("\nPrinted: %d\n", printf("---   PRINTF  ---\n%dx", 154564567));
	// ft_printf("--------------------------------------------------------------");
	// printf("\nPrinted: %d\n", ft_printf("--- FT_PRINTF ---\n%sx", "salut"));
	// printf("\nPrinted: %d\n", printf("---   PRINTF  ---\n%sx", "salut"));
	// ft_printf("--------------------------------------------------------------");
	// printf("\nPrinted: %d\n", ft_printf("--- FT_PRINTF ---\n%sx", "salut"));
	// printf("\nPrinted: %d\n", printf("---   PRINTF  ---\n%sx", "salut"));
	// ft_printf("--------------------------------------------------------------");
	// printf("\nPrinted: %d\n", ft_printf("--- FT_PRINTF ---\n%sx", "s"));
	// printf("\nPrinted: %d\n", printf("---   PRINTF  ---\n%sx", "s"));
	

	// ft_printf("--------------------------------------------------------------");
	// printf("\nPrinted: %d\n", ft_printf("--- FT_PRINTF ---\n%cx", 'a'));
	// printf("\nPrinted: %d\n", printf("---   PRINTF  ---\n%cx", 'a'));

	// ft_printf("--------------------------------------------------------------");
	// printf("\nPrinted: %d\n", ft_printf("--- FT_PRINTF ---\n%xx", 900));
	// printf("\nPrinted: %d\n", printf("---   PRINTF  ---\n%xx", 900));

	// ft_printf("--------------------------------------------------------------");
	// printf("\nPrinted: %d\n", ft_printf("--- FT_PRINTF ---\n%X", 567));
	// printf("\nPrinted: %d\n", printf("---   PRINTF  ---\n%X", 567));

	// ft_printf("--------------------------------------------------------------");
	// printf("\nPrinted: %d\n", ft_printf("--- FT_PRINTF ---\n%u", 123));
	// printf("\nPrinted: %d\n", printf("---   PRINTF  ---\n%u", 123));

	// ft_printf("--------------------------------------------------------------");
	// printf("\nPrinted: %d\n", ft_printf("--- FT_PRINTF ---\n%%"));
	// printf("\nPrinted: %d\n", printf("---   PRINTF  ---\n%%"));

	// ft_printf("--------------------------------------------------------------");
	// printf("\nPrinted: %d\n", ft_printf("--- FT_PRINTF ---\n%i", 555));
	// printf("\nPrinted: %d\n", printf("---   PRINTF  ---\n%i", 555));

	//ft_printf("--------------------------------------------------------------\n");
	//printf("\nPrinted: \n%d\n", ft_printf("%"));
	//printf("\nPrinted: \n%d\n", printf("%p\n", ptr));
	
}*/
