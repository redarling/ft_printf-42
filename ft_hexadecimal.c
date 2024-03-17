/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:51:57 by asyvash           #+#    #+#             */
/*   Updated: 2023/11/25 13:04:52 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_negative_to_hex(int number, int *len, char conversion)
{
	char	hex[9];
	int		i;
	int		nibble;

	i = 0;
	while (i < 8)
	{
		nibble = (number >> (4 * i)) & 0xF;
		if (conversion == 'x')
			hex[7 - i] = "0123456789abcdef"[nibble];
		else
			hex[7 - i] = "0123456789ABCDEF"[nibble];
		i++;
	}
	hex[8] = '\0';
	i = 0;
	while (hex[i])
	{
		ft_put(hex[i], len);
		i++;
	}
}

static void	ft_nonneg_to_hex(int number, int *len, char *base_character)
{
	char	string[25];
	int		i;

	i = 0;
	if (number == 0)
	{
		ft_put('0', len);
		return ;
	}
	while (number != 0)
	{
		string[i] = base_character [number % 16];
		number = number / 16;
		i++;
	}
	while (i--)
		ft_put(string[i], len);
}

void	ft_buffer(int number, int *len, char conversion)
{
	char	*base_character;

	if (number < 0)
		ft_negative_to_hex(number, len, conversion);
	else
	{
		if (conversion == 'x')
			base_character = "0123456789abcdef";
		else
			base_character = "0123456789ABCDEF";
		ft_nonneg_to_hex(number, len, base_character);
	}
}
