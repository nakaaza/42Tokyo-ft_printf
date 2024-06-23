/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:37:45 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/21 21:04:10 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			cnt;
	va_list		args;
	t_format	*format;

	cnt = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			format = parse_format(str);
			str += format -> chars_read;
			cnt += print_format(format, args);
			if (format -> str)
				free(format -> str);
			free(format);
		}
		else
			cnt += print_char(*str++);
	}
	va_end(args);
	return (cnt);
}
