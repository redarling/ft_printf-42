/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:54:15 by asyvash           #+#    #+#             */
/*   Updated: 2023/12/09 13:19:33 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

/*********•     %c      •**************/

void	ft_put(char c, int *len);

/*********•	%s	•**************/

void	ft_string(char *str, int *len);

/*********•     %p      •**************/

void	ft_pointer(void *ptr, int *len);

/*********•     %d %i      •***********/

void	ft_integer(int number, int *len);

/*********•     %u      •**************/

void	ft_unsigned_int(unsigned int number, int *len);

/*********•     %x %X      •***********/

void	ft_buffer(int number, int *len, char conversion);

/******•     auxiliary      •**********/

char	*ft_itoa(int n);

#endif
