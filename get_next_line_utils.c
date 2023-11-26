/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbron      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:07:11 by dongjle2          #+#    #+#             */
/*   Updated: 2023/11/25 21:14:24 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

typedef struct s_local_char_ptrs
{
	char	buffer[BUFFER_SIZE];
	char	*pstrjoin;
	char	*cp_strjoin;
}t_local_ptrs;

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

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	void	*mem;

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
	}
	return (-1);
}
