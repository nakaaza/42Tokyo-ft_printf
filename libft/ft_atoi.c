/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:23:05 by tnakaza           #+#    #+#             */
/*   Updated: 2024/05/22 19:53:46 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isdigit(int c);
int static	ft_isspace(char c);

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	res = 0;
	negative = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			negative = 1;
	while (ft_isdigit(*str))
		res = 10 * res - (*str++ - '0');
	return (negative * res);
}

int static	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'\
			|| c == '\v' || c == '\f' || c == '\r');
}
