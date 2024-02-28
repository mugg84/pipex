/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:42:13 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/25 10:42:28 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*copy;
	size_t			len;
	unsigned int	start;

	if (!s1)
		return (NULL);
	start = 0;
	len = ft_strlen(s1);
	while (*(s1 + start) && is_in_set(s1[start], (char *)set))
		start++;
	while (len > start && is_in_set(s1[len - 1], (char *)set))
		len--;
	copy = ft_substr(s1, start, (len - start));
	if (!copy)
		return (NULL);
	return (copy);
}
