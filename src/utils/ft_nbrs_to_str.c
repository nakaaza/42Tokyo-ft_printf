/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrs_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:11:25 by nakaaza           #+#    #+#             */
/*   Updated: 2024/06/10 17:17:21 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int static	count_udigit(unsigned int n, unsigned int base);
int static	count_pdigit(uintptr_t p);

void	int_to_str(int nbr, char sign_padding, t_format *format)
{
	char	*str;
	char	*padded_str;

	str = ft_itoa(nbr);
	if (!str)
		return ;
	if (sign_padding)
	{
		padded_str = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
		if (!padded_str)
			return ;
		padded_str[0] = sign_padding;
		ft_strlcat(padded_str, str, ft_strlen(str) + 2);
		format -> str = padded_str;
		format -> len = ft_strlen(str) + 1;
		free(str);
	}
	else
	{
		format -> str = str;
		format -> len = ft_strlen(str);
	}
	return ;
}

void	uint_to_str(unsigned int nbr, t_format *format)
{
	int		d;
	char	*res;

	d = count_udigit(nbr, 10);
	res = (char *)malloc((d + 1) * (int) sizeof(char));
	if (!res)
		return ;
	format -> str = res;
	format -> len = d;
	res[d] = '\0';
	while (--d >= 0)
	{
		res[d] = nbr % 10 + '0';
		nbr /= 10;
	}
	return ;
}

void	uint_to_hexstr(unsigned int nbr, int prefix, int capital, t_format *format)
{
	int		d;
	char	*res;
	int		r;

	d = count_udigit(nbr, 16) + prefix * 2;
	res = (char *)malloc((d + 1) * (int) sizeof(char));
	if (!res)
		return ;
	format -> str = res;
	format -> len = d;
	res[d] = '\0';
	if (prefix)
	{
		res[0] = '0';
		if (capital)
			res[1] = 'X';
		else
			res[1] = 'x';
	}
	while (--d >= prefix * 2)
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
