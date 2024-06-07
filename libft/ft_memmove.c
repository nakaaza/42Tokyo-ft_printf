/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:18:21 by tnakaza           #+#    #+#             */
/*   Updated: 2024/05/06 12:17:27 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) dst;
	if (dst < src)
	{
		while (tmp < (unsigned char *) dst + len)
			*tmp++ = *(unsigned char *) src++;
	}
	else if (src < dst)
	{
		tmp += len - 1;
		src += len - 1;
		while ((unsigned char *) dst <= tmp)
			*tmp-- = *(unsigned char *) src--;
	}
	return (dst);
}
