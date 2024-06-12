/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:18:15 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/12 19:23:20 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t static	print_nbr(int nbr);

void	print_binary(unsigned int num, int bit)
{
	while (bit-- > 0)
		print_char((int)((num >> bit) & 1) + '0');
}

void	print_params(t_format *format)
{
	print_char('<');
	print_char('[');
	print_binary(format -> flags, 5);
	print_char(']');
	print_char('[');
	print_nbr((int) format -> field_width);
	print_char(']');
	print_char('[');
	print_nbr((int) format -> precision);
	print_char(']');
	print_char('[');
	if (format -> long_double)
		print_char('L');
	print_char(format -> specifier);
	print_char(']');
	print_char('>');
}

size_t static	print_nbr(int nbr)
{
	char	*str;
	size_t	len;

	str = ft_itoa(nbr);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
