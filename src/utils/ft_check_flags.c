/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:28:42 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/07 11:34:38 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check_hash_flag(t_format *format)
{
	return (format -> flags & (1 << 4));
}

int	check_minus_flag(t_format *format)
{
	return (format -> flags & (1 << 3));
}

int	check_plus_flag(t_format *format)
{
	return (format -> flags & (1 << 2));
}

int	check_space_flag(t_format *format)
{
	return (format -> flags & (1 << 1));
}

int	check_zero_flag(t_format *format)
{
	return (format -> flags & (1 << 0));
}
