/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:38:05 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/15 00:05:36 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_format
{
	unsigned int	flags;
	unsigned int	field_width;
	int				precision;
	int				long_double;
	char			specifier;
	size_t			chars_read;
	char			*str;
	size_t			len;
}				t_format;

// ft_printf.c
int			ft_printf(const char *str, ...);

// ft_parse_format.c
t_format	*parse_format(const char *str);

// ft_update_format.c
void		update_format_str(t_format *format, char *new_str);
void		concat_format_str(t_format *format, char *head, char *tail);

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
size_t		print_formatted_str(t_format *format);

// ft_chars_to_str.c
void		char_to_str(char c, t_format *format);
void		str_to_str(char *s, t_format *format);

// ft_nbrs_to_str.c
void		int_to_str(int nbr, t_format *format);
void		uint_to_str(unsigned int nbr, t_format *format);
void		uint_to_hexstr(unsigned int nbr, int capital, t_format *format);
void		ptr_to_str(uintptr_t nbr, t_format *format);

// debugs.c
// TODO: delete
void		print_params(t_format *format);

#endif