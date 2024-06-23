/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrs_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:11:25 by nakaaza           #+#    #+#             */
/*   Updated: 2024/06/22 08:20:55 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int static	count_udigit(unsigned int n, unsigned int base);
char static	*uitohexa(unsigned int nbr, int capital);

void	int_to_str(int nbr, t_format *format)
{
	char	*str;
	int		digit_len;

	str = ft_itoa(nbr);
	if (!str)
		return ;
	update_format_str(format, "\0");
	if (nbr < 0)
		update_format_str(format, str);
	else
	{
		if (check_plus_flag(format))
			update_format_str(format, "+");
		else if (check_space_flag(format))
			update_format_str(format, " ");
		if (!(nbr == 0 && format -> precision == 0))
			concat_format_str(format, format -> str, str);
	}
	free(str);
	digit_len = format -> len - !ft_isdigit(*(format -> str));
	if (format -> precision > 0 && format -> precision > digit_len)
		pad_format_str(format, '0', format -> precision - digit_len, \
						!ft_isdigit(*(format -> str)));
	pad_field_width(format);
}

void	uint_to_str(unsigned int nbr, t_format *format)
{
	int		d;
	char	*str;

	d = count_udigit(nbr, 10);
	str = (char *)calloc(d + 1, sizeof(char));
	if (!str)
		return ;
	str[d] = '\0';
	if (format -> precision == 0 && nbr == 0)
		str[0] = '\0';
	else
	{
		while (--d >= 0)
		{
			str[d] = nbr % 10 + '0';
			nbr /= 10;
		}
	}
	update_format_str(format, str);
	free(str);
	if (format -> precision > 0 && (size_t)format -> precision > format -> len)
		pad_format_str(format, '0', format -> precision - format -> len, 0);
	pad_field_width(format);
}

void	uint_to_hexstr(unsigned int nbr, int capital, t_format *format)
{
	char	*str;

	if (nbr == 0)
		set_hash_flag(format, 0);
	str = uitohexa(nbr, capital);
	if (!str)
		return ;
	if (format -> precision == 0 && nbr == 0)
		str[0] = '\0';
	update_format_str(format, str);
	free(str);
	if (format -> precision > 0 && (size_t)format -> precision > format -> len)
		pad_format_str(format, '0', format -> precision - format -> len, 0);
	if (check_hash_flag(format))
	{
		if (capital)
			concat_format_str(format, "0X", format -> str);
		else
			concat_format_str(format, "0x", format -> str);
	}
	pad_field_width(format);
	return ;
}

int static	count_udigit(unsigned int n, unsigned int base)
{
	int	res;

	res = 0;
	if (n == 0)
		res = 1;
	while (n != 0)
	{
		res++;
		n /= base;
	}
	return (res);
}

char static	*uitohexa(unsigned int nbr, int capital)
{
	int		d;
	char	*res;
	int		r;

	d = count_udigit(nbr, 16);
	res = (char *)calloc(d + 1, sizeof(char));
	if (!res)
		return (NULL);
	res[d] = '\0';
	while (--d >= 0)
	{
		r = nbr % 16;
		if (r <= 9)
			res[d] = r + '0';
		else
		{
			if (capital)
				res[d] = r - 10 + 'A';
			else
				res[d] = r - 10 + 'a';
		}
		nbr /= 16;
	}
	return (res);
}
