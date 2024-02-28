/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:46:49 by mmughedd          #+#    #+#             */
/*   Updated: 2023/11/03 13:47:23 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\f')
		return (1);
	else if (c == '\n' || c == '\r' || c == '\v')
		return (1);
	return (0);
}

static int	ft_issign(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	return (0);
}

static int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		result;
	char	*ptr;

	sign = 1;
	result = 0;
	ptr = (char *)nptr;
	while (ft_isspace(*ptr))
		ptr++;
	if (ft_issign(*ptr))
	{
		sign *= ft_issign(*ptr);
		ptr++;
	}
	while (ft_isnum(*ptr))
	{
		result += (*ptr - '0');
		ptr++;
		if (ft_isnum(*ptr))
			result *= 10;
	}
	return (result * sign);
}
