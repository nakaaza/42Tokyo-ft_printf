/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:28:42 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/22 08:20:11 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_hash_flag(t_format *format, int val)
{
	format -> flags &= ~(!val << 4);
	return ;
}

void	set_minus_flag(t_format *format, int val)
{
	format -> flags &= ~(!val << 3);
	return ;
}

void	set_plus_flag(t_format *format, int val)
{
	format -> flags &= ~(!val << 2);
	return ;
}

void	set_space_flag(t_format *format, int val)
{
	format -> flags &= ~(!val << 1);
	return ;
}

void	set_zero_flag(t_format *format, int val)
{
	format -> flags &= ~(!val << 0);
	return ;
}
