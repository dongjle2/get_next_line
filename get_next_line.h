/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbron      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:02:53 by dongjle2          #+#    #+#             */
/*   Updated: 2023/11/21 22:58:39 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define BUFFER_SIZE 2
#include <stddef.h>

typdef struct s_node
{
	char			buf[BUFFER_SIZE + 1];
	struct s_node	*next;
}					t_node;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_memset(void *b int c, size_t len);
