/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:50:26 by tnakaza           #+#    #+#             */
/*   Updated: 2024/05/05 18:58:07 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int static	count_digit(int n);

char	*ft_itoa(int n)
{
	int		d;
	int		sign;
	char	*res;

	sign = 1;
	if (n < 0)
		sign = -1;
	d = count_digit(n);
	if (sign == -1)
		d++;
	res = (char *)malloc((d + 1) * (int) sizeof(char));
	if (!res)
		return (NULL);
	res[d] = '\0';
	if (sign == -1)
		res[0] = '-';
	while (--d >= (1 - sign) / 2)
	{
		res[d] = sign * (n % 10) + '0';
		n /= 10;
	}
	return (res);
}

int static	count_digit(int n)
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
