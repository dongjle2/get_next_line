/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:02:53 by dongjle2          #+#    #+#             */
/*   Updated: 2023/12/04 21:14:10 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
ssize_t	find_nl_idx(char *str);
int		concat_buffer(char	**stored_str, char buffer[BUFFER_SIZE + 1]);
char	*ret_from_stored_string(char **stored_str, size_t nl_idx);
char	*ret_concat(char **stored_str, char buffer[BUFFER_SIZE + 1], ssize_t nl_idx);
#endif
