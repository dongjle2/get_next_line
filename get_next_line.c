/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbron      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:55:22 by dongjle2          #+#    #+#             */
/*   Updated: 2023/11/26 22:36:15 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"

update_static_strjoin(t_local_ptrs *pptrs)
{
	
}

char	*alloc_a_line(t_local_ptrs ptrs, ssize_t nl_idx)
{
	
}

char	*gnl_bufffer_join(t_local_ptrs ptrs, ssize_t nl_idx)
{
	char	*pbuffer;
	char	*mem;
	size_t	len_static;

	len_static = ft_strlen(static_strjoin);
	pbuffer = ptrs.buf;
	pbuffer[nl_idx + 1] = 0;
	mem = malloc(len_static + nl_idx + 1);
	if (!mem)
		return (mem);
	ft_memmove(mem, static_strjoin, len_static);
	ft_memmove(mem + len_static, pbuffer, nl_idx + 1);
//	static_strjoin = 
	return (mem);
}

char	*get_next_line(int fd)
{
	t_local_ptrs	ptrs;
	static char		*static_strjoin;
	char			dup_buffer[BUFFER_SIZE + 1];
	ssize_t			ret_read;
	ssize_t			nl_idx;

	ret_read = read(fd, buffer, BUFFER_SIZE);
	nl_idx = find_nl_idx(buffer);	
	if (0 <= nl_idx)
	{
		strlcpy(dup_buffer, t_ptrs.buf);
		dup_buffer[nl_idx + 1] = 0;
		t_ptrs.pstrjoin = ft_strjoin(static_strjoin, dup_buffer);
		static_strjoin = t_ptrs.buf + BUFFER_SIZE + 1;
		return (t_ptrs.pstrjoin);
	}
	else if (ret_read == BUFFER_SIZE)
	{
		concat_buffer(&ptrs, )
		pstrjoin = ft_strjoin(static_strjoin, ptrs.buffer);
		cp_strjoin = ft_strdup(pstrjoin);
		static_strjoin = cp_strjoin;
		free(pstrjoin);
	}
	else		//end of the file
		
}
#include <stdio.h>
int	main(void)
{
	int fd = open("./a.txt", O_RDONLY);
	int	ret;
	int	i = 0;
	if (fd == -1)
	{
		return (-1);	
	}
	char	buf[BUFFER_SIZE];
	while (i++ < 10)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		printf("%d\n", ret);
		printf("%s\n", buf);
	}
	return (0);
}
