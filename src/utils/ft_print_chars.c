/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:42:37 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/07 11:34:38 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	print_str(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
