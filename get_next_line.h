/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmouta <helmouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:12:25 by helmouta          #+#    #+#             */
/*   Updated: 2025/07/21 16:08:13 by helmouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100 
# endif

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_lnalloc(int fd, char *s);
char	*ft_lnnext(char *str);
char	*ft_lnrem(char *line);
void	ft_bzero(char *s, size_t n);
void	ft_strjoin_helper(char *s1, char *s2, char *dest);
size_t	ft_lnlen(char *str);

#endif
