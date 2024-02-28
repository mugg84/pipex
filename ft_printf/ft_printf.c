/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:44:46 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/25 10:44:48 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_getarg(char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_uint(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		len += ft_print_ptr(va_arg(args, void *));
	else if (format == '%')
		len += ft_printchar(va_arg(args, int));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_strchr("cspdiuxX", format[++i]))
				len += ft_getarg(format[i], args);
			else if (format[i] == '%')
				len += ft_printchar('%');
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
