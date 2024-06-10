/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:54:41 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/10 17:11:33 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_format(t_format *format, va_list args)
{
	size_t	cnt;
	char	padding;

	cnt = 0;
	padding = ' ';
	if (format -> specifier == 'c')
	{
		char	c;

		c = va_arg(args, int);
		char_to_str(c, format);
	}
	else if (format -> specifier == 's')
	{
		char	*s;

		s = va_arg(args, char *);
		str_to_str(s, format);
	}
	else if (format -> specifier == 'p')
	{
		void	*p;

		p = va_arg(args, void *);
		ptr_to_str((uintptr_t) p, format);
	}
	else if (format -> specifier == 'd' || format -> specifier == 'i')
	{
		int		d;
		char	sign_padding;

		d = va_arg(args, int);
		sign_padding = '\0';
		if (check_plus_flag(format) && d >= 0)
			sign_padding = '+';
		else if (check_space_flag(format) && d >= 0)
			sign_padding = ' ';
		int_to_str(d, sign_padding, format);
	}
	else if (format -> specifier == 'u')
	{
		unsigned int	u;

		u = va_arg(args, unsigned int);
		uint_to_str(u, format);
	}
	else if (format -> specifier == 'x')
	{
		int		x;

		x = va_arg(args, int);
		uint_to_hexstr(x, check_hash_flag(format), 0, format);
	}
	else if (format -> specifier == 'X')
	{
		int		x;

		x = va_arg(args, int);
		uint_to_hexstr(x, check_hash_flag(format), 1, format);
	}

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
			if (check_zero_flag(format))
				padding = '0';
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
