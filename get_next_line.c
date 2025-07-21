/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmouta <helmouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:07:37 by helmouta          #+#    #+#             */
/*   Updated: 2025/07/21 20:18:47 by helmouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

size_t	ft_lnlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(char *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_lnalloc(fd, str);
	if (!str)
	{
		//free(str);
		return (NULL);
	}
	dest = ft_lnnext(str);
	if(!dest)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = ft_lnrem(str);
	return (dest);
}

// int	main(void)
// {
// 	char	*str;
// 	int		i;
// 	int		fd;
// 	fd = open("1char.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 10)
// 	{
// 		str = get_next_line(fd);
// 		if (!str)
// 		{
// 			printf("NULL");
// 			break;
// 		}
// 		//printf("line [%02d], %s", i, str);
// 		printf("%s", str);
// 		free(str);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }

//simulate with malloc = -1 for possible leaks

