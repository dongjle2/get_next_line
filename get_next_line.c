/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:26:45 by dongjle2          #+#    #+#             */
/*   Updated: 2023/12/05 15:26:45 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	resize_str(t_stored_str *i)
{
	char	*tmp;
	size_t	idx;

	idx = 0;
	i->size *= 2;
	tmp = malloc(i->size);
	if (tmp == NULL)
	{
		free(i->stored_str);
		i->stored_str = NULL;
		return (-1);
	}
	while (idx < i->size)
		tmp[idx++] = 0;
	ft_memmove(tmp, i->stored_str, i->size / 2);
	free(i->stored_str);
	i->stored_str = NULL;
	i->stored_str = tmp;
	return (1);
}

int	read_file(int fd, t_stored_str *i, ssize_t	*num_read)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		nl_buffer;

	while (1)
	{
		*num_read = read(fd, buffer, BUFFER_SIZE);
		if (*num_read <= 0)
			return (*num_read);
		buffer[*num_read] = 0;
		while (i->size < i->len + BUFFER_SIZE + 1)
		{
			if (resize_str(i) == -1)
				return (-2);
		}
		ft_memmove(i->stored_str + i->len, buffer, *num_read + 1);
		nl_buffer = find_nl_idx(buffer);
		i->len += *num_read;
		// if (0 <= nl_buffer || *num_read != BUFFER_SIZE)///
		if (0 <= nl_buffer)
			break ;
	}
	return (*num_read);
}

char	*print_single_line(t_stored_str *i, ssize_t *nl_idx, ssize_t *num_read)
{
	*nl_idx = find_nl_idx(i->stored_str + i->start_idx);
	i->tmp_chr = (i->stored_str + i->start_idx)[*nl_idx + 1];
	if (*nl_idx == -1)
	{
		if (*num_read <= 0)
		{
			i->eof = 1;
			if (*(i->stored_str + i->start_idx) == 0 || *num_read == -1)
				return (NULL);
			else
				return (ft_strdup(i->stored_str + i->start_idx));
		}
	}
	(i->stored_str + i->start_idx)[*nl_idx + 1] = 0;
	return (ft_strdup(i->stored_str + i->start_idx));
}

void	mv_line(t_stored_str *i, ssize_t *nl_idx, char *single_line)
{
	// if (i->stored_str == NULL)
		// return ;
	// if (*num_read == -1 || i->eof == 1 || single_line == NULL)
	if (i->eof == 1 || single_line == NULL)
	{
		free(i->stored_str);
		i->stored_str = NULL;
		i->start_idx = 0;
		i->tmp_chr = 0;
		i->size = 128;
		i->len = 0;
		i->rd_flag = 1;
		i->eof = 0;
		return ;
	}
	(i->stored_str + i->start_idx)[*nl_idx + 1] = i->tmp_chr;
	i->start_idx += *nl_idx + 1;
	if (0 <= find_nl_idx(i->stored_str + i->start_idx))
		i->rd_flag = 0;
	else
		i->rd_flag = 1;
	return ;
}

char	*get_next_line(int fd)
{
	static t_stored_str	i;
	char				*single_line;
	ssize_t				nl_idx;
	ssize_t				num_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// if (i.eof == 1)
	// 	return (NULL);
	if (i.stored_str == NULL)
	{
		if (init_static(&i) == 0)
			return (NULL);
	}
	num_read = 0;
	single_line = NULL;
	if (i.rd_flag)
		num_read = read_file(fd, &i, &num_read);
	if (num_read == -2)
		return (NULL);
	single_line = print_single_line(&i, &nl_idx, &num_read);
	mv_line(&i, &nl_idx, single_line);
	return (single_line);
}

// int	main(void)
// {
// 	int fd = open("./a.txt", O_RDONLY);
// 	int	i = 1;
// 	char	*gnl;
// 	while ((gnl = get_next_line(fd)))
// 	{
// 		printf("%d - %s\n", i++, gnl);
// 		free(gnl);
// 	}
// 	printf("%d - %s\n", i++, get_next_line(fd));
// 	printf("%d - %s\n", i++, "");
// 	close(fd);
// 	return (0);
// }
