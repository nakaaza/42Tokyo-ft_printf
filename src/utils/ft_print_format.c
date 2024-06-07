/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:54:41 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/07 12:27:53 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_format(t_format *format, va_list args)
{
	size_t	cnt;
	char	padding;

	cnt = 0;
	padding = ' ';
	// 各フォーマットの処理ではstrを返すようにして、出力はprint_format側で担う？
	// print_hexあたりが困りそう
	if (format -> specifier == 'c')
	{
		char	c;
		c = va_arg(args, int);
		print_str("\033[1D");
		print_str("x");
		cnt = print_char(c);
	}
	else if (format -> specifier == 's')
	{
		char	*str;
		str = va_arg(args, char *);
		if (str)
			cnt = print_str(str);
		else
			cnt = print_str("(null)");
	}
	else if (format -> specifier == 'p')
	{
		void	*p;
		p = va_arg(args, void *);
		print_str("0x");
		cnt = print_ptr_addr((uintptr_t) p, 0) + 2;
	}
	else if (format -> specifier == 'd' || format -> specifier == 'i')
	{
		int		d;
		size_t	head_count;

		d = va_arg(args, int);
		head_count = 0;
		if (check_plus_flag(format) && d >= 0)
		{
			print_char('+');
			head_count++;
		}
		else if (check_space_flag(format) && d >= 0)
		{
			print_char(' ');
			head_count++;
		}
		cnt = print_nbr(d) + head_count;
	}
	else if (format -> specifier == 'u')
	{
		unsigned int	u;
		u = va_arg(args, unsigned int);
		cnt = print_unbr(u);
	}
	else if (format -> specifier == 'x')
	{
		int		x;
		size_t	head_count;

		x = va_arg(args, int);
		head_count = 0;
		if (check_hash_flag(format))
			head_count += print_str("0x");
		cnt = print_hex((unsigned int)x, 0, 0) + head_count;
	}
	else if (format -> specifier == 'X')
	{
		int		x;
		size_t	head_count;

		x = va_arg(args, int);
		head_count = 0;
		if (check_hash_flag(format))
			head_count += print_str("0X");
		cnt = print_hex((unsigned int)x, 1, 0) + head_count;
	}
	if (format -> field_width > cnt)
	{
		if (check_minus_flag(format))
		{
			while (cnt++ < format -> field_width)
				put_char(' ');
		}
		else
		{
			if (check_zero_flag)
				padding = '0';
		}
	}
	return (cnt);
}
