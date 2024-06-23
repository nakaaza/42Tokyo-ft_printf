/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:54:41 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/22 08:20:03 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_format(t_format *format, va_list args)
{
	size_t	cnt;

	cnt = 0;
	if (format -> specifier == 'c')
		char_to_str(va_arg(args, int), format);
	else if (format -> specifier == 's')
		str_to_str(va_arg(args, char *), format);
	else if (format -> specifier == 'p')
		ptr_to_str((uintptr_t) va_arg(args, void *), format);
	else if (format -> specifier == 'd' || format -> specifier == 'i')
		int_to_str(va_arg(args, int), format);
	else if (format -> specifier == 'u')
		uint_to_str(va_arg(args, unsigned int), format);
	else if (format -> specifier == 'x')
		uint_to_hexstr(va_arg(args, int), 0, format);
	else if (format -> specifier == 'X')
		uint_to_hexstr(va_arg(args, int), 1, format);
	else if (format -> specifier == '%')
		char_to_str('%', format);
	cnt += print_formatted_str(format);
	return (cnt);
}

void	pad_field_width(t_format *format)
{
	size_t	pad_len;

	if (format -> field_width > format -> len)
	{
		if (ft_strchr("diuxX", format -> specifier) \
			&& format -> precision != -1)
			set_zero_flag(format, 0);
		pad_len = format -> field_width - format -> len;
		if (check_minus_flag(format))
			pad_format_str(format, ' ', pad_len, format -> len);
		else if (check_zero_flag(format))
		{
			if (ft_strchr("xX", format -> specifier) \
				&& check_hash_flag(format))
				pad_format_str(format, '0', pad_len, 2);
			else if (ft_strchr("di", format -> specifier) \
				&& !ft_isdigit(*(format -> str)))
				pad_format_str(format, '0', pad_len, 1);
			else
				pad_format_str(format, '0', pad_len, 0);
		}
		else
			pad_format_str(format, ' ', pad_len, 0);
	}
	return ;
}
