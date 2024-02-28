/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:55:28 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/25 10:43:32 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_hexa_len(unsigned int n)
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

void	convert_to_hexa(unsigned int n, char up_or_low)
{
	if (n >= 16)
	{
		convert_to_hexa(n / 16, up_or_low);
		convert_to_hexa(n % 16, up_or_low);
	}
	else
	{
		if (n <= 9)
			ft_print_nbr(n);
		else
		{
			if (up_or_low == 'x')
				ft_printchar(n - 10 + 'a');
			else
				ft_printchar(n - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int n, char up_or_low)
{
	int	len;

	if (n == 0)
		len = ft_print_nbr(n);
	else
	{
		convert_to_hexa(n, up_or_low);
		len = get_hexa_len(n);
	}
	return (len);
}
