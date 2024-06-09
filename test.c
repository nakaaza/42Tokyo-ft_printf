/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:45:04 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/09 23:23:08 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/ft_printf.h"
#include <stdio.h>
#include <string.h>

void	test_c(void);
void	test_s(void);
void	test_p(void);
void	test_d(void);
void	test_i(void);
void	test_u(void);
void	test_x(void);
void	test_X(void);

char	*g_test_template = "|[]%$|[#]%#$|[-]%-$|[+]%+$|[ ]% $|[0]%0$|[12]%12$|[]%$|[]%$|";

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
	if (ft_strchr("cdiu", specifier))
		ft_printf_cnt = ft_printf(test_str, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data);
	else
		ft_printf_cnt = ft_printf(test_str, data, data, data, data, data, data, data, data, data);
	print_str(" -> cnt = ");
	print_nbr((int)ft_printf_cnt);
	print_str("\nprintf:\t\t");
	if (ft_strchr("cdiu", specifier))
		printf_cnt = printf(test_str, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data, *(int *)data);
	else
		printf_cnt = printf(test_str, data, data, data, data, data, data, data, data, data);
	print_str(" -> cnt = ");
	print_nbr((int)printf_cnt);
	print_str("\n\n");
}

void	test_c(void)
{
	char	*data;
	char	*test_str;

	data = (char *)malloc(sizeof(char));
	*data = 'a';
	test_str = set_test_str('c');
	put_test(test_str, data, 'c');
	free(data);
	free(test_str);
}

void	test_s(void)
{
	char	*data;
	char	*test_str;

	data = NULL;
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
	*data = 0;
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
	*data = UINT_MAX;
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
	*data = 42;
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
