/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrs_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:11:25 by nakaaza           #+#    #+#             */
/*   Updated: 2024/06/19 18:21:37 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int static	count_udigit(unsigned int n, unsigned int base);

void	int_to_str(int nbr, t_format *format)
{
	char	*str;
	size_t	str_len;

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
	str_len = ft_strlen(str);
	free(str);
	if (nbr < 0)
		str_len--;
	if (format -> precision > (int)str_len)
		pad_format_str(format, '0', format -> precision - str_len, \
						!ft_isdigit(*(format -> str)));
}

void	uint_to_str(unsigned int nbr, t_format *format)
{
	int		d;
	char	*str;
	char	*padded_str;

	d = count_udigit(nbr, 10);
	str = (char *)malloc((d + 1) * (int) sizeof(char));
	if (!str)
		return ;
	format -> str = str;
	format -> len = d;
	str[d] = '\0';
	if (format -> precision == 0 && nbr == 0)
	{
		str[0] = '\0';
		format -> len = 0;
		return ;
	}
	while (--d >= 0)
	{
		str[d] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (format -> precision > 0 && (size_t)format -> precision > format -> len)
	{
		padded_str = (char *)ft_calloc(format -> precision + 1, sizeof(char));
		if (!padded_str)
			return ;
		ft_memset(padded_str, '0', format -> precision - format -> len);
		ft_strlcat(padded_str, format -> str, format -> precision + 1);
		free(format -> str);
		format -> str = padded_str;
		format -> len = format -> precision;
	}
	return ;
}

void	uint_to_hexstr(unsigned int nbr, int capital, t_format *format)
{
	int		d;
	char	*res;
	int		r;
	char	*padded_str;

	if (nbr == 0)
		format -> flags &= ~(1 << 4);
	d = count_udigit(nbr, 16);
	res = (char *)malloc((d + 1) * (int) sizeof(char));
	if (!res)
		return ;
	format -> str = res;
	format -> len = d;
	res[d] = '\0';
	if (format -> precision == 0 && nbr == 0)
	{
		res[0] = '\0';
		format -> len = 0;
		return ;
	}
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
	if (format -> precision != -1 \
		&& (size_t)format -> precision > format -> len)
	{
		padded_str = (char *)ft_calloc(format -> precision + 1, sizeof(char));
		if (!padded_str)
			return ;
		ft_memset(padded_str, '0', format -> precision - format -> len);
		ft_strlcat(padded_str, format -> str, format -> precision + 1);
		free(format -> str);
		format -> str = padded_str;
		format -> len = format -> precision;
	}
	if (check_hash_flag(format))
	{
		padded_str = (char *)ft_calloc(format -> len + 3, sizeof(char));
		if (!padded_str)
			return ;
		padded_str[0] = '0';
		if (capital)
			padded_str[1] = 'X';
		else
			padded_str[1] = 'x';
		ft_strlcat(padded_str, format -> str, format -> len + 3);
		free(format -> str);
		format -> str = padded_str;
		format -> len = format -> len + 2;
	}
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
