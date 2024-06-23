/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrs_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:11:25 by nakaaza           #+#    #+#             */
/*   Updated: 2024/06/21 23:56:56 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int static	count_pdigit(uintptr_t p);

void	ptr_to_str(uintptr_t nbr, t_format *format)
{
	int		d;
	char	*res;
	int		r;

	d = count_pdigit(nbr) + 2;
	res = (char *)calloc(d + 1, sizeof(char));
	if (!res)
		return ;
	res[d] = '\0';
	res[0] = '0';
	res[1] = 'x';
	while (--d >= 2)
	{
		r = nbr % 16;
		if (r <= 9)
			res[d] = r + '0';
		else
			res[d] = r - 10 + 'a';
		nbr /= 16;
	}
	update_format_str(format, res);
	free(res);
	pad_field_width(format);
	return ;
}

int static	count_pdigit(uintptr_t p)
{
	int	res;

	res = 0;
	if (p == 0)
		res = 1;
	while (p != 0)
	{
		res++;
		p /= 16;
	}
	return (res);
}
