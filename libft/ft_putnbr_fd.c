/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:44:10 by tnakaza           #+#    #+#             */
/*   Updated: 2024/05/13 18:50:22 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar_fd(char c, int fd);
int static	count_digit(int n);
int	static	calc_power(int n, int e);

void	ft_putnbr_fd(int n, int fd)
{
	int		d;
	int		sign;
	int		p;
	char	c;

	sign = 1;
	if (n < 0)
		sign = -1;
	d = count_digit(n);
	if (sign == -1)
		ft_putchar_fd('-', fd);
	while (d-- > 0)
	{
		p = calc_power(10, d);
		c = n / p * sign + '0';
		ft_putchar_fd(c, fd);
		n %= p;
	}
	return ;
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

int	static	calc_power(int n, int e)
{
	int	res;

	res = 1;
	while (e-- > 0)
		res *= n;
	return (res);
}
