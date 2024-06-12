/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:45:04 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/12 19:24:11 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/ft_printf.h"
#include <stdio.h>
#include <string.h>

void			test_c(void);
void			test_s(void);
void			test_p(void);
void			test_d(void);
void			test_i(void);
void			test_u(void);
void			test_x(void);
void			test_X(void);
size_t static	print_str(char *str);
size_t static	print_nbr(int nbr);

// char	*g_test_template = "|[]%$|[#]%#$|[-]%-$|[+]%+$|[ ]% $|[10]%10$|[010]%010$|[.5]%.5$|[3.5]%3.5$|[05]%05$|";
// char	*g_test_template = "|[04(lf)]%04$|[1(fl)]%1$|[.12(lp)]%.12$|[.1(pl)]%.1$|[+1.5(flp)]%+1.5$|[1.2(fpl)]%1.2$|[ 5.7(lfp)]% 5.7$|[07.5(lpf)]%07.5$|[5.1(plf)]%5.1$|[2.1(pfl)]%2.1$|";
// char	*g_test_template = "|[.2]%.2$|[.3]%.3$|[.4]%.4$|[.5]%.5$|[.6]%.6$|[.7]%.7$|[.8]%.8$|[.9]%.9$|[.10]%.10$|[.11]%.11$|";
// char	*g_test_template = "|[]%%|[#]%#%|[-]%-%|[+]%+%|[ ]% %|[0]%0%|[10]%10%|[.5]%.5%|[3.5]%3.5%|[05]%05%|";
char	*g_test_template = "|[#4]%#4$|[#12]%#12$|[#04]%#04$|[#012]%#012$|[#+]%#+$|[#-12]%#-12$|[# ]%# $|[#12.]%#12.$|[#5.12]%#5.12$|[#012.5]%012.5$|";

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	setvbuf(stdout, NULL, _IONBF, 0);
	if (strcmp(argv[1], "all") == 0 || strchr(argv[1], 'c'))
		test_c();
	if (strcmp(argv[1], "all") == 0 || strchr(argv[1], 's'))
		test_s();
	if (strcmp(argv[1], "all") == 0 || strchr(argv[1], 'p'))
		test_p();
	if (strcmp(argv[1], "all") == 0 || strchr(argv[1], 'd'))
		test_d();
	if (strcmp(argv[1], "all") == 0 || strchr(argv[1], 'i'))
		test_i();
	if (strcmp(argv[1], "all") == 0 || strchr(argv[1], 'u'))
		test_u();
	if (strcmp(argv[1], "all") == 0 || strchr(argv[1], 'x'))
		test_x();
	if (strcmp(argv[1], "all") == 0 || strchr(argv[1], 'X'))
		test_X();
}

char	*set_test_str(char specifier)
{
	size_t	test_temp_len;
	char	*test_str;

	test_temp_len = ft_strlen(g_test_template);
	test_str = malloc(test_temp_len + 1);
	ft_memmove(test_str, g_test_template, test_temp_len + 1);
	while (*test_str)
	{
		if (*test_str == '$')
			*test_str = specifier;
		test_str++;
	}
	return (test_str - test_temp_len);
}	

void	put_test(char *test_str, void *data, char specifier)
{
	size_t	ft_printf_cnt;
	size_t	printf_cnt;

	ft_printf_cnt = 0;
	printf_cnt = 0;
	print_str(test_str);
	print_str("\nft_printf:\t");
	if (specifier == 'c')
		ft_printf_cnt = ft_printf(test_str, *(char *)data, *(char *)data, *(char *)data, *(char *)data, *(char *)data, *(char *)data, *(char *)data, *(char *)data, *(char *)data, *(char *)data);
	else if (specifier == 's')
		ft_printf_cnt = ft_printf(test_str, (char *)data, (char *)data, (char *)data, (char *)data, (char *)data, (char *)data, (char *)data, (char *)data, (char *)data, (char *)data);
	else if (specifier == 'p')
		ft_printf_cnt = ft_printf(test_str, data, data, data, data, data, data, data, data, data, data);
	else if (specifier == 'd' || specifier == 'i')
		ft_printf_cnt = ft_printf(test_str, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data);
	else if (specifier == 'u')
		ft_printf_cnt = ft_printf(test_str, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data);
	else if (specifier == 'x' || specifier == 'X')
		ft_printf_cnt = ft_printf(test_str, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data);
	print_str(" -> cnt = ");
	print_nbr((int)ft_printf_cnt);
	print_str("\nprintf:\t\t");
	if (specifier == 'c')
		printf_cnt = printf(test_str, *(char *)data, *(char *)data, *(char *)data, *(char *)data, *(char *)data, *(char *)data, *(char *)data, *(char *)data, *(char *)data, *(char *)data);
	else if (specifier == 's')
		printf_cnt = printf(test_str, (char *)data, (char *)data, (char *)data, (char *)data, (char *)data, (char *)data, (char *)data, (char *)data, (char *)data, (char *)data);
	else if (specifier == 'p')
		printf_cnt = printf(test_str, data, data, data, data, data, data, data, data, data, data);
	else if (specifier == 'd' || specifier == 'i')
		printf_cnt = printf(test_str, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data);
	else if (specifier == 'u')
		printf_cnt = printf(test_str, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data, *(unsigned int *)data);
	else if (specifier == 'x' || specifier == 'X')
		printf_cnt = printf(test_str, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data);
	print_str(" -> cnt = ");
	print_nbr((int)printf_cnt);
	print_str("\n\n");
}

void	test_c(void)
{
	char	*data;
	char	*test_str;

	data = (char *)malloc(sizeof(char));
	*data = 'T';
	test_str = set_test_str('c');
	put_test(test_str, data, 'c');
	free(data);
	free(test_str);
}

void	test_s(void)
{
	char	*data;
	char	*test_str;

	data = "-";
	test_str = set_test_str('s');
	put_test(test_str, data, 's');
	free(test_str);
}

void	test_p(void)
{
	void	*data;
	char	*test_str;

	data = malloc(1);
	test_str = set_test_str('p');
	put_test(test_str, data, 'p');
	free(data);
	free(test_str);
}

void	test_d(void)
{
	int		*data;
	char	*test_str;

	data = (int *)malloc(sizeof(int));
	*data = 42;
	test_str = set_test_str('d');
	put_test(test_str, data, 'd');
	free(data);
	free(test_str);
}

void	test_i(void)
{
	int		*data;
	char	*test_str;

	data = (int *)malloc(sizeof(int));
	*data = -42;
	test_str = set_test_str('i');
	put_test(test_str, data, 'i');
	free(data);
	free(test_str);
}

void	test_u(void)
{
	unsigned int	*data;
	char			*test_str;

	data = (unsigned int *)malloc(sizeof(unsigned int));
	*data = 42;
	test_str = set_test_str('u');
	put_test(test_str, data, 'u');
	free(data);
	free(test_str);
}

void	test_x(void)
{
	int		*data;
	char	*test_str;

	data = (int *)malloc(sizeof(int));
	*data = 0;
	test_str = set_test_str('x');
	put_test(test_str, data, 'x');
	free(data);
	free(test_str);
}

void	test_X(void)
{
	int		*data;
	char	*test_str;

	data = (int *)malloc(sizeof(int));
	*data = 42;
	test_str = set_test_str('X');
	put_test(test_str, data, 'X');
	free(data);
	free(test_str);
}

size_t static	print_str(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

size_t static	print_nbr(int nbr)
{
	char	*str;
	size_t	len;

	str = ft_itoa(nbr);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
