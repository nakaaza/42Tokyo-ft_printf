/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:38:05 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/07 11:25:41 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_format
{
	unsigned int	flags;
	unsigned int	field_width;
	unsigned int	precision;
	int				long_double;
	char			specifier;
	size_t			chars_read;
}				t_format;

// ft_printf.c
int			ft_printf(const char *str, ...);

// ft_parse_format.c
t_format	*parse_format(const char *str);

// ft_check_flags.c
int			check_hash_flag(t_format *format);
int			check_minus_flag(t_format *format);
int			check_plus_flag(t_format *format);
int			check_space_flag(t_format *format);
int			check_zero_flag(t_format *format);

// ft_print_format.c
size_t		print_format(t_format *format, va_list args);

// ft_print_chars.c
size_t		print_char(char c);
size_t		print_str(char *str);

// ft_print_nbrs.c
size_t		print_nbr(int nbr);
size_t		print_unbr(unsigned int nbr);
size_t		print_hex(unsigned int nbr, int capital, size_t len);

// ft_print_ptr.c
size_t		print_ptr_addr(uintptr_t ptr_addr, size_t len);

// debugs.c
// TODO: delete
void		print_binary(unsigned int num, int bit);
void		print_params(t_format *format);

#endif