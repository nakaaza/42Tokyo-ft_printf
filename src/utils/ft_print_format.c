/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:54:41 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/12 20:01:12 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_format(t_format *format, va_list args)
{
	size_t	cnt;
	char	padding;
	char	*padded_str;

	cnt = 0;
	padding = ' ';
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
	if (format -> field_width > format -> len)
	{
		if (check_minus_flag(format))
		{
			cnt += print_formatted_str(format);
			while (cnt < format -> field_width)
			{
				print_char(padding);
				cnt++;
			}
		}
		else
		{
			if (check_zero_flag(format) \
				&& (!ft_strchr("diuxX", format -> specifier) \
					|| (ft_strchr("diuxX", format -> specifier) \
						&& format -> precision == -1)))
			{
				padding = '0';
				if (ft_strchr("di", format -> specifier) \
					&& format -> precision == -1 \
					&& !ft_isdigit(*(format -> str)))
				{
					print_char(*(format -> str));
					cnt++;
					padded_str = (char *)ft_calloc(ft_strlen(format -> str), \
													sizeof(char));
					ft_strlcpy(padded_str, format -> str + 1, \
								ft_strlen(format -> str));
					free(format -> str);
					format -> str = padded_str;
					format -> len = ft_strlen(padded_str);
				}
				if (ft_strchr("xX", format -> specifier) \
					&& format -> precision == -1 \
					&& check_hash_flag(format) \
					&& ft_strncmp(format -> str, "0", 2) != 0)
				{
					print_char('0');
					if (format -> specifier == 'x')
						print_char('x');
					else if (format -> specifier == 'X')
						print_char('X');
					cnt += 2;
					padded_str = (char *)calloc(ft_strlen(\
													ft_strchr(format -> str, \
														format -> specifier)), \
												sizeof(char));
					ft_strlcpy(padded_str, \
								ft_strchr(format -> str, \
											format -> specifier) + 1, \
								ft_strlen(ft_strchr(format -> str, \
													format -> specifier)));
					free(format -> str);
					format -> str = padded_str;
					format -> len = ft_strlen(padded_str);
				}
			}
			while (cnt + format -> len < format -> field_width)
			{
				print_char(padding);
				cnt++;
			}
			cnt += print_formatted_str(format);
		}
	}
	else
		cnt += print_formatted_str(format);
	return (cnt);
}
