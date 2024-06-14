/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrs_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:11:25 by nakaaza           #+#    #+#             */
/*   Updated: 2024/06/15 00:27:20 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int static	count_udigit(unsigned int n, unsigned int base);
int static	count_pdigit(uintptr_t p);

void	int_to_str(int nbr, t_format *format)
{
	char	*str;
	char	*padded_str;
	size_t	precision_pad;
	char	sign_padding[2];

	// 各属性をパラメータで持って、最後に一回だけmallocする方がいい？
	sign_padding[0] = '\0';
	if (nbr < 0)
		sign_padding[0] = '-';
	else if (check_plus_flag(format))
		sign_padding[0] = '+';
	else if (check_space_flag(format))
		sign_padding[0] = ' ';
	str = ft_itoa(nbr);
	if (!str)
		return ;
	update_format_str(format, str);
	if (nbr < 0)
		update_format_str(format, str + 1);
	else if (format -> precision == 0 && nbr == 0)
		update_format_str(format, "\0");
	free(str);
	if (format -> precision > (int)format -> len)
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
	if (sign_padding[0])
	{
		// concat_format_str(format, sign_padding, format -> str);
		padded_str = (char *)ft_calloc(format -> len + 2, sizeof(char));
		if (!padded_str)
			return ;
		padded_str[0] = sign_padding[0];
		ft_strlcat(padded_str, format -> str, format -> len + 2);
		free(format -> str);
		format -> str = padded_str;
		format -> len = format -> len + 1;
	}
	return ;
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

void	ptr_to_str(uintptr_t nbr, t_format *format)
{
	int		d;
	char	*res;
	int		r;

	d = count_pdigit(nbr) + 2;
	res = (char *)malloc((d + 1) * (int) sizeof(char));
	if (!res)
		return ;
	format -> str = res;
	format -> len = d;
	res[d] = '\0';
	res[0] = '0';
	res[1] = 'x';
	while (--d >= 2)
	{
		r = nbr % 16;
		if (r <= 9)
			res[d] = r + '0';
		else
			res[d] = r - 10 + 'a';
		nbr /= 16;
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

int static	count_pdigit(uintptr_t p)
{
	int	res;

	res = 0;
	if (p == 0)
		res = 1;
	while (p != 0)
	{
		res++;
		p /= 16;
	}
	return (res);
}
