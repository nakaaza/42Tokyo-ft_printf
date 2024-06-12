/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:09:16 by tnakaza           #+#    #+#             */
/*   Updated: 2024/05/21 18:47:31 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	n;
	int		l;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (n <= start)
		l = 0;
	else if (n - start > len)
		l = len;
	else
		l = n - start;
	res = (char *)malloc((l + 1) * (int) sizeof(char));
	if (res == NULL)
		return (NULL);
	res[l] = '\0';
	while (0 <= --l)
		res[l] = s[start + l];
	return (res);
}
