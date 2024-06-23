/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:42:37 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/22 08:25:37 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	print_formatted_str(t_format *format)
{
	size_t	cnt;
	char	*formatted_str;

	cnt = 0;
	if (!(format -> str))
		return (cnt);
	formatted_str = format -> str;
	while (cnt < format -> len)
		cnt += print_char(*formatted_str++);
	return (cnt);
}
