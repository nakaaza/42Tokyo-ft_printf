/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:00:36 by nakaaza           #+#    #+#             */
/*   Updated: 2024/06/10 17:21:23 by tnakaza          ###   ########.fr       */
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

	if (!s)
	{
		str = (char *)malloc(7 * sizeof(char));
		ft_strlcpy(str, "(null)", 7);
	}
	else
	{
		str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		ft_strlcpy(str, s, ft_strlen(s) + 1);
	}
	format -> str = str;
	format -> len = ft_strlen(str);
	return ;
}
