/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:40:03 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/25 10:42:28 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static long int	num_digits(long int n)
{
	long int	i;

	i = 0;
	if (n <= 0)
	{
		i = 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	conv_to_str(long int l_n, int dig, char *str)
{
	int	len;

	len = 0;
	str[dig] = '\0';
	if (l_n < 0)
	{
		str[0] = '-';
		l_n *= -1;
		len++;
	}
	while (dig-- > len)
	{
		str[dig] = (l_n % 10) + '0';
		l_n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int			dig;
	long int	l_n;
	char		*str;

	l_n = n;
	dig = num_digits(l_n);
	str = malloc(sizeof(char) * (dig + 1));
	if (!str)
		return (NULL);
	conv_to_str(l_n, dig, str);
	return (str);
}
