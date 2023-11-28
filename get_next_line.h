/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:02:53 by dongjle2          #+#    #+#             */
/*   Updated: 2023/11/28 19:33:06 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_local_char_ptrs
{
	char	buffer[BUFFER_SIZE];
	char	*tmp;
}	t_local_ptrs;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char  const *s2);
ssize_t	find_nl_idx(char *str);
int		concat_buffer(t_local_ptrs *ptrs, char **static_strjoin);
char	*get_next_line(int fd);
void	init_ptrs(t_local_ptrs *ptrs);
char	*malloc_a_line(t_local_ptrs *ptrs, char **static_strjoin, ssize_t nl_idx);

#endif
