/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:07:11 by dongjle2          #+#    #+#             */
/*   Updated: 2023/11/27 22:25:40 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	l;

	if (!s)
		return (0);
	l = 0;
	while (*s++)
		l++;
	return (l);
}

char	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;

	if (pdst < psrc)
	{
		while (len--)
			*pdst++ = *psrc++;
	}
	else if (psrc < pdst)
	{
		while (len--)
			pdst[len] = psrc[len];
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*mem;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	mem = malloc(len_s1 + len_s2 + 1);
	if (!mem)
		return (mem);
	ft_memmove(mem, s1, len_s1);
	ft_memmove(mem + len_s1, s2, len_s2);
	return (mem);
}

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*mem;

	len_s1 = ft_strlen(s1);
	mem = malloc(len_s1 + 1);
	if (!mem)
		return (mem);
	mem[len_s1] = 0;
	return (ft_memmove(mem, s1, len_s1));
}

ssize_t	find_nl_idx(char *str)
{
	size_t	idx;

	if (!str)
		return (-1);
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}
