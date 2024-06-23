/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:00:36 by nakaaza           #+#    #+#             */
/*   Updated: 2024/06/22 09:18:59 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	char_to_str(char c, t_format *format)
{
	char	*str;

	str = (char *)calloc(2, sizeof(char));
	if (!str)
		return ;
	str[0] = c;
	str[1] = '\0';
	update_format_str(format, str);
	free(str);
	if (c == '\0')
		(format -> len)++;
	pad_field_width(format);
	if (*(format -> str) != '\0' && c == '\0')
		(format -> len)++;
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
		str = (char *)calloc(cpy_len, sizeof(char));
		ft_strlcpy(str, "(null)", cpy_len);
	}
	else
	{
		if (format -> precision != -1 \
			&& (size_t)format -> precision < ft_strlen(s))
			cpy_len = format -> precision + 1;
		else
			cpy_len = ft_strlen(s) + 1;
		str = (char *)calloc(cpy_len, sizeof(char));
		ft_strlcpy(str, s, cpy_len);
	}
	update_format_str(format, str);
	free(str);
	pad_field_width(format);
}
