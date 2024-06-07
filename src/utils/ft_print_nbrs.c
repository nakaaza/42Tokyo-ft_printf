/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:43:57 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/07 11:34:38 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int static	count_udigit(unsigned int n);
char static	*ft_uitoa(unsigned int n);

size_t	print_nbr(int nbr)
{
	char	*str;
	size_t	len;

	str = ft_itoa(nbr);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

size_t	print_unbr(unsigned int nbr)
{
	char	*str;
	size_t	len;

	str = ft_uitoa(nbr);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

size_t	print_hex(unsigned int nbr, int capital, size_t len)
{
	if (nbr >= 16)
		return (print_hex(nbr / 16, capital, len) \
				+ print_hex(nbr % 16, capital, len));
	else
	{
		if (nbr <= 9)
			print_char((nbr + '0'));
		else
		{
			if (capital)
				print_char((nbr - 10 + 'A'));
			else
				print_char((nbr - 10 + 'a'));
		}
		return (len + 1);
	}
}

char static	*ft_uitoa(unsigned int n)
{
	int		d;
	char	*res;

	d = count_udigit(n);
	res = (char *)malloc((d + 1) * (int) sizeof(char));
	if (!res)
		return (NULL);
	res[d] = '\0';
	while (--d >= 0)
	{
		res[d] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

int static	count_udigit(unsigned int n)
{
	int	res;

	res = 0;
	if (n == 0)
		res = 1;
	while (n != 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}
