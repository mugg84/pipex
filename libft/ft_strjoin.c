/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:55:06 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/25 10:42:28 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		tot_len;
	int		i;
	char	*s3;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tot_len = len1 + len2;
	s3 = malloc(sizeof(char) * (tot_len + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (i < tot_len)
	{
		s3[i] = s2[i - len1];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
