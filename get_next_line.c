/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:55:22 by dongjle2          #+#    #+#             */
/*   Updated: 2023/11/27 23:14:29 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"

char	*malloc_a_line(t_local_ptrs *ptrs, char *static_strjoin, ssize_t nl_idx)
{
	unsigned char	tmp;
	char			*pbuffer;
	char			*mem;
	size_t			len_static;

	len_static = ft_strlen(static_strjoin);
	pbuffer = ptrs->buffer;
	tmp = ptrs->buffer[nl_idx + 1];
	ptrs->buffer[nl_idx + 1] = 0;
	ptrs->tmp = ft_strjoin(static_strjoin, ptrs->buffer);
	free(static_strjoin);
	ptrs->buffer[nl_idx + 1] = tmp;
	pbuffer += (nl_idx + 1);
	static_strjoin = ft_strdup(pbuffer);
	return (ptrs->tmp);
}

void	init_ptrs(t_local_ptrs *ptrs)
{
	size_t	i;

	i = BUFFER_SIZE;
	while (i--)
		ptrs->buffer[i] = 0;
	ptrs->tmp = NULL;
}

char	*get_next_line(int fd)
{
	t_local_ptrs	ptrs;
	static char		*static_strjoin;
	ssize_t			ret_read;
	ssize_t			nl_idx;

	while (1)
	{
		init_ptrs(&ptrs);
		ret_read = read(fd, ptrs.buffer, BUFFER_SIZE);
		if (fd == -1 || ret_read <= 0)
			return (NULL);
		nl_idx = find_nl_idx(ptrs.buffer);
		if (nl_idx <= 0)							//nl not found, concat
		{
			ptrs.tmp = ft_strjoin(static_strjoin, ptrs.buffer);
			free(static_strjoin);
			static_strjoin = ptrs.tmp;
			if (ret_read != BUFFER_SIZE)			//end of file
				return (static_strjoin);
		}
		else										//nl_found
			return (malloc_a_line(&ptrs, static_strjoin, nl_idx));
	}
}
#include <stdio.h>
int	main(void)
{
	int fd = open("./a.txt", O_RDONLY);
	int	ret;
	int	i;

	i = 0;
	if (fd == -1)
		return (-1);	
	char	buf[BUFFER_SIZE];
	while (i < 15)
	{
		printf("%s\n", get_next_line(fd));
		i++;
	}
	return (0);
}
