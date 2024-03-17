/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:51:22 by asyvash           #+#    #+#             */
/*   Updated: 2023/11/25 13:04:30 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_integer(int number, int *len)
{
	char	*str;

	str = ft_itoa(number);
	ft_string(str, len);
	free(str);
}

void	ft_unsigned_int(unsigned int number, int *len)
{
	if (number >= 10)
		ft_unsigned_int(number / 10, len);
	ft_put(number % 10 + '0', len);
}

static void	put_ptr(unsigned long long ptr, int *len)
{
	static char	digits[] = "0123456789abcdef";

	if (ptr >= 16)
		put_ptr(ptr / 16, len);
	write(1, &digits[ptr % 16], 1);
	(*len)++;
}

void	ft_pointer(void *ptr, int *len)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*len) += 2;
	put_ptr((unsigned long long)ptr, len);
}
