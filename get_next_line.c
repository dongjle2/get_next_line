/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:55:22 by dongjle2          #+#    #+#             */
/*   Updated: 2023/11/30 23:39:47 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

char	*ret_from_stored_string(char **stored_str, ssize_t nl_idx)
{
	char	*tmp_str;
	char	*ret_str;
	char	*tmp_stored_str;
	char	tmp_char;

	tmp_char = (*stored_str)[nl_idx + 1];
	stored_str[nl_idx + 1] = 0;
	ret_str = ft_strdup(*stored_str);
	// if (ret_str == NULL)
	// 	return (NULL);
	*stored_str[nl_idx + 1] = tmp_char;
	tmp_str = *stored_str + nl_idx + 1;
	if (!tmp_str)
	{
		free(*stored_str);
		*stored_str = NULL;
		return (NULL);
	}
	tmp_stored_str = ft_strdup(tmp_str);
	// if (tmp_stored_str == NULL)
	// 	return (NULL);
	free(*stored_str);
	*stored_str = NULL;
	*stored_str = tmp_stored_str;
	return (ret_str);
}

char	*ret_concat(char **stored_str, char buffer[BUFFER_SIZE + 1], ssize_t nl_idx)
{
	unsigned char	tmp_char;
	char			*ret_str;
	char			*pbuffer;

	tmp_char = buffer[nl_idx + 1];
	buffer[nl_idx + 1] = 0;
	pbuffer = buffer;
	ret_str = ft_strjoin(*stored_str, pbuffer);
	// if (ret_str == NULL)
	// 	return (NULL);
	free(*stored_str);
	*stored_str = NULL;
	buffer[nl_idx + 1] = tmp_char;
	pbuffer = buffer + nl_idx + 1;
	*stored_str = ft_strdup(pbuffer);
	// if (*stored_str == NULL)
	// 	return (NULL);
	return (ret_str);
}

int	concat_buffer(char	**stored_str, char buffer[BUFFER_SIZE + 1])
{
	char	*tmp;

	tmp = NULL;
	if (*stored_str)
	{
		tmp = ft_strjoin(*stored_str, buffer);
		// if (tmp == NULL)
		// 	return (-1);
		free(*stored_str);
		*stored_str = NULL;
		*stored_str = tmp;
	}
	else
	{
		*stored_str = ft_strdup(buffer);
		// if (*stored_str == NULL)
		// 	return (-1);
	}
	return (1);
}

char	*start_read(char **stored_str, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	ret_read;
	ssize_t	nl_idx;

	nl_idx = -1;
	buffer[BUFFER_SIZE] = 0;
	while (nl_idx < 0)
	{
		//init_buffer
		ret_read = read(fd, buffer, BUFFER_SIZE);
		if (ret_read <= 0)
			return (NULL);
		nl_idx = find_nl_idx(buffer);
		if (nl_idx < 0)							//nl not found, concat
		{
			if (concat_buffer(stored_str, buffer) < 0)
				return (NULL);
			if (ret_read != BUFFER_SIZE)		//end of the file
			{
				buffer[ret_read] = 0;
				if (concat_buffer(stored_str, buffer) < 0)
					return (NULL);
			}
		}
	}
	return (ret_concat(stored_str, buffer, nl_idx));
}

char	*get_next_line(int fd)
{
	static char		*stored_str;
	ssize_t			nl_idx;
	char			*single_line;

	// nl_idx = -1;
	// while (nl_idx < 0)
	while (1)
	{
		nl_idx = find_nl_idx(stored_str);
		if (0 <= nl_idx)
			return (ret_from_stored_string(&stored_str, nl_idx));
		single_line = start_read(&stored_str, fd);
		return (single_line);

	}
	// return (stored_str);
}

#include <stdio.h>
int	main(void)
{
	int fd = open("./a.txt", O_RDONLY);
	int	i;
	char	*gnl;
	i = 0;
	while (i < 17)
	{
		gnl = get_next_line(fd);
		write(1, gnl, ft_strlen(gnl));
		i++;
	}
	return (0);
}

// char	*multi_nl(t_vars *i, ssize_t nl_idx)
// {
// 	char	tmp_char;
// 	char	*tmp_ptr;
// 	char	*plocal_buffer;
// 	char	local_buffer[BUFFER_SIZE + 1];

// 	plocal_buffer = ft_memmove(local_buffer, i->buffer + i->last_nl_idx, BUFFER_SIZE + 1 - i->last_nl_idx);
// 	// plocal_buffer += i->last_nl_idx;
// 	tmp_char = i->buffer[nl_idx + 1];
// 	i->buffer[nl_idx + 1] = 0;
// 	tmp_ptr = ft_strjoin(i->concat, local_buffer);
// 	if (tmp_ptr == NULL)
// 		return (NULL);
// 	free(i->concat);
// 	i->buffer[nl_idx + 1] = tmp_char;
// 	i->concat = tmp_ptr;
// 	i->last_nl_idx = nl_idx;
// 	return (ft_strdup(tmp_ptr));
// }	

// char	*multi_nl(t_vars *i, ssize_t nl_idx)
// {
// 	char	tmp_char;
// 	char	*tmp_ptr;
// 	char	*plocal_buffer;
// 	char	local_buffer[BUFFER_SIZE + 1];
// 	ssize_t	nl_idx;

// 	nl_idx = find_nl_idx(i->last_nl_idx, i->buffer);
// 	plocal_buffer = ft_memmove(local_buffer, i->buffer + i->last_nl_idx, BUFFER_SIZE + 1 - i->last_nl_idx);
// 	// plocal_buffer += i->last_nl_idx;
// 	tmp_char = i->buffer[nl_idx + 1];
// 	i->buffer[nl_idx + 1] = 0;
// 	tmp_ptr = ft_strjoin(i->concat, local_buffer);
// 	if (tmp_ptr == NULL)
// 		return (NULL);
// 	free(i->concat);
// 	i->buffer[nl_idx + 1] = tmp_char;
// 	i->concat = tmp_ptr;
// 	i->last_nl_idx = nl_idx;
// 	return (ft_strdup(tmp_ptr));
// }	