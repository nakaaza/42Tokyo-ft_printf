/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:35:14 by tnakaza           #+#    #+#             */
/*   Updated: 2024/05/07 23:23:04 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = NULL;
	while (*s != '\0')
	{
		if (*s == (char) c)
			res = (char *) s;
		s++;
	}
	if ((char) c == '\0')
		res = (char *) s;
	return (res);
}
