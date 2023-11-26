/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42heilbron      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:02:53 by dongjle2          #+#    #+#             */
/*   Updated: 2023/11/26 22:34:47 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define BUFFER_SIZE 2
#include <stddef.h>

typedef struct s_local_char_ptrs
{
	char	buffer[BUFFER_SIZE];
	char	*pstrjoin;
	char	*cp_strjoin;
}	t_local_ptrs;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char  const *s2);
