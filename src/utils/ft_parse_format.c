/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:34:13 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/07 11:34:38 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t static	parse_flags(const char *str, t_format *format);
size_t static	parse_field_width(const char *str, t_format *format);
size_t static	parse_precision(const char *str, t_format *format);
size_t static	parse_specifier(const char *str, t_format *format);

t_format	*parse_format(const char *str)
{
	t_format	*format;
	size_t		chars_read;

	chars_read = 0;
	format = (t_format *) ft_calloc(1, sizeof(t_format));
	chars_read += parse_flags(str, format);
	chars_read += parse_field_width(str + chars_read, format);
	chars_read += parse_precision(str + chars_read, format);
	chars_read += parse_specifier(str + chars_read, format);
	format -> chars_read = chars_read;
	return (format);
}

size_t static	parse_flags(const char *str, t_format *format)
{
	size_t			chars_read;
	unsigned int	*flags;

	chars_read = 0;
	flags = &(format -> flags);
	while (ft_strchr("#-+ 0", str[chars_read]))
	{
		if (str[chars_read] == '#')
			*flags |= (1 << 4);
		else if (str[chars_read] == '-')
			*flags |= (1 << 3);
		else if (str[chars_read] == '+')
			*flags |= (1 << 2);
		else if (str[chars_read] == ' ')
			*flags |= (1 << 1);
		else if (str[chars_read] == '0')
			*flags |= (1 << 0);
		chars_read++;
	}
	if (check_plus_flag(format))
		*flags &= ~(1 << 1);
	if (check_minus_flag(format))
		*flags &= ~(1 << 0);
	return (chars_read);
}

size_t static	parse_field_width(const char *str, t_format *format)
{
	size_t			chars_read;

	// TODO: *への対応
	chars_read = 0;
	format -> field_width = ft_atoi(str);
	while (ft_isdigit(str[chars_read]))
		chars_read++;
	return (chars_read);
}

size_t static	parse_precision(const char *str, t_format *format)
{
	size_t			chars_read;

	// TODO: *への対応
	chars_read = 0;
	if (*str == '.')
	{
		chars_read++;
		format -> precision = ft_atoi(str + 1);
		while (ft_isdigit(str[chars_read]))
			chars_read++;
	}
	return (chars_read);
}

size_t static	parse_specifier(const char *str, t_format *format)
{
	size_t	chars_read;

	chars_read = 0;
	format -> long_double = 0;
	if (*str == 'L')
	{
		format -> long_double = 1;
		chars_read++;
		str++;
	}
	format -> specifier = *str;
	chars_read++;
	return (chars_read);
}
