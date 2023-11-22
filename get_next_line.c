/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbron      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:55:22 by dongjle2          #+#    #+#             */
/*   Updated: 2023/11/21 22:03:53 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"

char	*get_next_line(int fd)
{
	static t_node	*head;
	static t_node	*tail;
	t_node			*node;
	int				ret_read;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!node)
		return (node);
	
	ret_read = read(fd, node.buf, BUFFER_SIZE);
	while(0 < ret_read)
	{
		if (ft_strchr((const char *)node.buf, '\n'))
			read_a_line();

		cur_prt = &node;
	}

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
