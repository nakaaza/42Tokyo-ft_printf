/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakaaza <nakaaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:00:36 by nakaaza           #+#    #+#             */
/*   Updated: 2024/06/07 17:18:28 by nakaaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*char_to_str(char c)
{
	char *str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*str_to_str(char *s)
{
	char	*str;

	if (!s)
	{
		str = (char *)malloc(7 * sizeof(char));
		ft_strlcpy(str, "(null)", 7);
	}
	else
	{
		str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
		ft_strlcpy(str, s, ft_strlen(str));
	}
	return (str);
}