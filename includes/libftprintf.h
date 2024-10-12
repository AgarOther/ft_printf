/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:10:41 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/12 10:11:58 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		count_conversions(const char *str);
int		print_conversion(const char *str, va_list arg);
int		ft_putstr(char *s);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_strlen(const char *s);
int		is_corrupted(const char *str);
int		is_conversion(const char *c);
int		ft_intlen(int n);
int		ft_print_hexadecimal(int n, int is_upper);
char	*ft_strlower(char *str);
char	*ft_strdup(const char *s, int is_upper);
#endif