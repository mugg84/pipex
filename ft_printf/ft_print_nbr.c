/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:43:50 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/25 10:43:32 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_nbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_printstr(str);
	free(str);
	return (len);
}
