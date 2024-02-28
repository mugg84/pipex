/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:14:35 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/25 10:42:28 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*dst;

	if (!src && !dest)
		return (dest);
	s = (unsigned char *)src;
	dst = (unsigned char *)dest;
	i = 0;
	if (dst > s)
	{
		while (n-- > 0)
			dst[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			dst[i] = s[i];
			i++;
		}
	}
	return (dest);
}
