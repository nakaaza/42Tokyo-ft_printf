/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:59:38 by tnakaza           #+#    #+#             */
/*   Updated: 2024/05/08 22:32:38 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s);
	res = (char *)malloc((len + 1) * (size_t) sizeof(char));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	while (0 < len--)
		res[len] = s[len];
	return (res);
}
