/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:46:51 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/07 11:34:38 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_ptr_addr(uintptr_t ptr_addr, size_t len)
{
	if (ptr_addr >= 16)
		return (print_ptr_addr(ptr_addr / 16, len) \
				+ print_ptr_addr(ptr_addr % 16, len));
	else
	{
		if (ptr_addr <= 9)
			print_char((ptr_addr + '0'));
		else
			print_char((ptr_addr - 10 + 'a'));
	}
	return (len + 1);
}
