/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:46:09 by tnakaza           #+#    #+#             */
/*   Updated: 2024/05/06 13:28:04 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t len);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	cpy_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dstsize - 1 < src_len)
		cpy_len = dstsize - 1;
	else
		cpy_len = src_len;
	ft_memcpy(dst, src, cpy_len);
	dst[cpy_len] = '\0';
	return (src_len);
}
