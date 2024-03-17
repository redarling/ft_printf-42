/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:17:17 by asyvash           #+#    #+#             */
/*   Updated: 2023/12/09 13:29:27 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_find(char conversion, va_list *vl, int *len)
{
	if (conversion == 'c')
		ft_put(va_arg(*vl, int), len);
	else if (conversion == 's')
		ft_string(va_arg(*vl, char *), len);
	else if (conversion == 'p')
		ft_pointer(va_arg(*vl, void *), len);
	else if (conversion == 'd' || conversion == 'i')
		ft_integer(va_arg(*vl, int), len);
	else if (conversion == 'u')
		ft_unsigned_int(va_arg(*vl, unsigned int), len);
	else if (conversion == 'x' || conversion == 'X')
		ft_buffer(va_arg(*vl, int), len, conversion);
	else if (conversion == '%')
		ft_put('%', len);
}

int	ft_printf(const char *format, ...)
{
	va_list	vl;
	int		i;
	int		len;

	if (!format)
		return (-1);
	i = -1;
	len = 0;
	va_start(vl, format);
	while (i++, format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		else if (format[i] == '%')
		{
			i++;
			ft_find(format[i], &vl, &len);
		}
		else
			ft_put((char)format[i], &len);
	}
	va_end(vl);
	return (len);
}
