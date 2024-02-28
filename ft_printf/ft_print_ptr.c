/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:54:26 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/25 10:43:32 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ptr_len(unsigned long long int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_convert_ptr(unsigned long long int n)
{
	if (n >= 16)
	{
		ft_convert_ptr(n / 16);
		ft_convert_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_printchar(n + '0');
		else
			ft_printchar(n - 10 + 'a');
	}
}

int	ft_print_ptr(void *n)
{
	int					len;
	unsigned long long	addr;

	len = 0;
	addr = (unsigned long long)n;
	if (!n)
	{
		len += ft_printstr("(nil)");
		return (len);
	}
	len += ft_printstr("0x");
	len += ptr_len(addr);
	ft_convert_ptr(addr);
	return (len);
}
