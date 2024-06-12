/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:23:36 by tnakaza           #+#    #+#             */
/*   Updated: 2024/05/21 21:58:36 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
size_t static	count_arr_len(char const *s, char c);
void static		free_arr(char **arr, int cnt);
size_t static	append_arr(char **res, const char *s, char c, size_t n);

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	**res;
	size_t	appended;

	if (!s)
		return (NULL);
	n = count_arr_len(s, c);
	res = (char **)malloc((n + 1) * (int) sizeof(char *));
	if (res == NULL)
		return (NULL);
	*(res + n) = NULL;
	appended = append_arr(res, s, c, n);
	if (appended != n)
	{
		free_arr(res, appended);
		return (NULL);
	}
	return (res);
}

size_t static	count_arr_len(char const *s, char c)
{
	size_t	cnt;

	if (*s == '\0')
		return (0);
	cnt = 0;
	while (*++s != '\0')
	{
		if (*s == c && *(s - 1) != c)
			cnt++;
	}
	if (*(s - 1) == c)
		cnt--;
	return (cnt + 1);
}

void static	free_arr(char **arr, int cnt)
{
	while (0 < cnt--)
		free(*(arr + cnt));
	free(arr);
	return ;
}

size_t static	append_arr(char **res, const char *s, char c, size_t n)
{
	size_t	l;
	size_t	i;
	char	*substr;

	i = 0;
	while (i < n)
	{
		l = ft_strchr(s, c) - s;
		if (l != 0)
		{
			substr = ft_substr(s, 0, l);
			if (!substr)
				return (i);
			else
			{
				*(res + i++) = substr;
				s += l;
			}
		}
		else
			s++;
	}
	return (i);
}
