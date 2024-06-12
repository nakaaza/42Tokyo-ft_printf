/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:00:36 by nakaaza           #+#    #+#             */
/*   Updated: 2024/06/12 19:47:52 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	char_to_str(char c, t_format *format)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return ;
	str[0] = c;
	str[1] = '\0';
	format -> str = str;
	format -> len = 1;
	return ;
}

void	str_to_str(char *s, t_format *format)
{
	char	*str;
	size_t	cpy_len;

	if (!s)
	{
		if (format -> precision != -1 && format -> precision < 6)
			cpy_len = format -> precision + 1;
		else
			cpy_len = 7;
		str = (char *)malloc(cpy_len * sizeof(char));
		ft_strlcpy(str, "(null)", cpy_len);
	}
	else
	{
		if (format -> precision != -1 \
			&& (size_t)format -> precision < ft_strlen(s))
			cpy_len = format -> precision + 1;
		else
			cpy_len = ft_strlen(s) + 1;
		str = (char *)malloc(cpy_len * sizeof(char));
		ft_strlcpy(str, s, cpy_len);
	}
	format -> str = str;
	format -> len = ft_strlen(str);
	return ;
}
