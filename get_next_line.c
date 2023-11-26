/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbron      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:55:22 by dongjle2          #+#    #+#             */
/*   Updated: 2023/11/25 21:24:10 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"

update_static_strjoin(char buffer[BUFFER_SIZE], char *pstrjoin, char *)
char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*pstrjoin;
	char		*cp_strjoin;
	static char	*static_strjoin;
	ssize_t		ret_read;
	ssize_t		nl_idx;

	ret_read = read(fd, buffer, BUFFER_SIZE);
	nl_idx = find_nl_idx(buffer);	
	if (0 <= nl_idx)
	{
		if (nl_idx != BUFFER_SIZE - 1)
			buffer[nl_idx] + 1] = 0;
		pstrjoin = ft_strjoin(static_strjoin, buffer);
		
		if (0 <= nl_idx(buffer))	//
		{
			
		}
		else
		{
			pstrjoin = ft_strjoin(static_strjoin, buffer);
			cp_strjoin = ft_strdup(pstrjoin);
			static_strjoin = cp_strjoin;
			free(pstrjoin);
		}
	}
	else if (ret_read < BUFFER_SIZE)
		return a line;
	else
		
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
