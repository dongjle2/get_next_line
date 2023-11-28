/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:55:22 by dongjle2          #+#    #+#             */
/*   Updated: 2023/11/28 23:00:12 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

char	*malloc_a_line(t_local_ptrs *ptrs, char **static_strjoin, ssize_t nl_idx)
{
	unsigned char	tmp;
	char			*pbuffer;
	char			null_buffer[BUFFER_SIZE + 1];

	// pbuffer = ptrs->buffer;
	pbuffer = ft_memmove(null_buffer, ptrs->buffer, ft_strlen(ptrs->buffer) + 1);
	if (nl_idx + 1 == BUFFER_SIZE)
		tmp = 0;
	else
	{
		tmp = ptrs->buffer[nl_idx + 1];
		ptrs->buffer[nl_idx + 1] = 0;
	}
	ptrs->tmp = ft_strjoin(*static_strjoin, ptrs->buffer);
	if (ptrs->tmp == NULL)
		return (NULL);
	free(*static_strjoin);
	*static_strjoin = NULL;
	ptrs->buffer[nl_idx + 1] = tmp;
	pbuffer += (nl_idx + 1);
	*static_strjoin = ft_strdup(pbuffer);
	if (*static_strjoin == NULL)
		return (NULL);
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

int	concat_buffer(t_local_ptrs *ptrs, char **static_strjoin)
{
	if (*static_strjoin)
	{
		ptrs->tmp = ft_strjoin(*static_strjoin, ptrs->buffer);
		if (ptrs->tmp == NULL)
			return (-1);
		free(*static_strjoin);
		*static_strjoin = ptrs->tmp;
	}
	else
	{
		*static_strjoin = ft_strdup(ptrs->buffer);
		if (*static_strjoin == NULL)
			return (-1);
	}
	return (1);
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
		if (ret_read <= 0)
			return (NULL);
		nl_idx = find_nl_idx(ptrs.buffer);
		if (nl_idx < 0)							//nl not found, concat
		{
			if (concat_buffer(&ptrs, &static_strjoin) < 0)
				return (NULL);
			if (ret_read != BUFFER_SIZE)			//end of file
				return (static_strjoin);
		}
		else										//nl_found
			return (malloc_a_line(&ptrs, &static_strjoin, nl_idx));
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	int fd = open("./a.txt", O_RDONLY);
// 	int	i;
// 	char	*gnl;
// 	i = 0;
// 	while (i < 17)
// 	{
// 		gnl = get_next_line(fd);
// 		write(1, gnl, ft_strlen(gnl));
// 		i++;
// 	}
// 	return (0);
// }
