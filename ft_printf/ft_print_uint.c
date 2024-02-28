/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:31:55 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/25 10:43:32 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	num_dig(unsigned int u)
{
	int	len;

	if (u == 0)
		len = 1;
	else
		len = 0;
	while (u)
	{
		u /= 10;
		len++;
	}
	return (len);
}

char	*unitoa(unsigned int u)
{
	int		len;
	char	*str;

	len = num_dig(u);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (u % 10) + '0';
		u /= 10;
	}
	return (str);
}

int	ft_print_uint(unsigned int u)
{
	int		len;
	char	*str;

	str = unitoa(u);
	len = ft_printstr(str);
	free(str);
	return (len);
}
