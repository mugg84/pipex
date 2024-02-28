/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:14:01 by mmughedd          #+#    #+#             */
/*   Updated: 2024/02/25 10:43:04 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "libft.h"

int	ft_printf(const char *format, ...);

int	ft_printchar(int c);

int	ft_printstr(char *str);

int	ft_print_nbr(int n);

int	ft_print_uint(unsigned int n);

int	ft_print_hex(unsigned int n, char up_or_low);

int	ft_print_ptr(void *n);

#endif
