/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbron      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:07:11 by dongjle2          #+#    #+#             */
/*   Updated: 2023/11/21 21:35:40 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	l;

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

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;

	d = (unsigned char *)b;
	while (len--)
	{
		*b == (unsigned char)c;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	mem = malloc(count * size);
	if (!mem)
		return (mem);
	return (ft_memset(mem, 0, count * size));
}

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	void	*mem;

	len_s1 = ft_strlen(s1);
	mem = malloc(len_s1 + 1);
	if (!mem)
		return (mem);
	return (ft_memmove(mem, s1, len_s1));
}

char	*ft_strchr(const char *s, int c)
{
	size_t				l;
	const unsigned char	*ps;
	
	ps = (const unsigned char *)s;
	while (ps*)
	{
		if (*ps == (unsigned char)c)
			return ((char *)ps);
		ps++;
	}
	if (!(unsigned char)c)
	{
		l = ft_strlen(s);
		return ((char *)ps + l);
	}
	return (NULL);














