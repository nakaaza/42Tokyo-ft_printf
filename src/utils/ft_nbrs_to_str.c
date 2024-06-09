/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrs_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakaaza <nakaaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:11:25 by nakaaza           #+#    #+#             */
/*   Updated: 2024/06/07 17:31:42 by nakaaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int static	count_udigit(unsigned int n);
char static	*ft_uitoa(unsigned int n);

char	*int_to_str(int nbr)
{
	char	*str;

	str = ft_itoa(nbr);
	if (!str)
		return (NULL);
	return (str);
}

char	*uint_to_str(unsigned int nbr)
{
	char	*str;

	str = ft_uitoa(nbr);
	if (!str)
		return (NULL);
	return (str);
}

char	*uint_to_hexstr(unsigned int nbr, int capital)
{
	char	*str;

	str = (char *)malloc(6 * sizeof(char));
	if (capital + nbr - nbr)
		ft_strlcpy(str, "(HEX)", 6);
	else
		ft_strlcpy(str, "(hex)", 6);
	return (str);
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
