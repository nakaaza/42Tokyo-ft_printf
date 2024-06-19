/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:14:30 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/19 18:03:07 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	update_format_str(t_format *format, char *new_str)
{
	size_t	len;
	char	*buff;

	len = ft_strlen(new_str);
	buff = (char *)ft_calloc(len + 1, sizeof(char));
	if (!buff)
		return ;
	ft_strlcpy(buff, new_str, len + 1);
	if (format -> str != NULL)
		free(format -> str);
	format -> str = buff;
	format -> len = len;
	return ;
}

void	concat_format_str(t_format *format, char *head, char *tail)
{
	size_t	head_len;
	size_t	tail_len;
	char	*buff;

	head_len = ft_strlen(head);
	tail_len = ft_strlen(tail);
	buff = (char *)ft_calloc(head_len + tail_len + 1, sizeof(char));
	if (!buff)
		return ;
	ft_strlcpy(buff, head, head_len + 1);
	ft_strlcat(buff, tail, head_len + tail_len + 1);
	if (format -> str != NULL)
		free(format -> str);
	format -> str = buff;
	format -> len = head_len + tail_len;
	return ;
}

void	pad_format_str(t_format *format, char pad_char, \
						size_t len, size_t offset)
{
	char	*head;
	char	*tail;
	char	*padding;

	head = ft_substr(format -> str, 0, offset);
	if (!head)
		return ;
	tail = ft_substr(format -> str, offset, ft_strlen(format -> str) - offset);
	if (!tail)
		return ;
	padding = (char *)ft_calloc(len + 1, sizeof(char));
	if (!padding)
		return ;
	ft_memset(padding, pad_char, len);
	concat_format_str(format, head, padding);
	concat_format_str(format, format -> str, tail);
	free(head);
	free(padding);
	free(tail);
	return ;
}
