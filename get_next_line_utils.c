/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helmouta <helmouta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:23:02 by helmouta          #+#    #+#             */
/*   Updated: 2025/07/21 18:16:22 by helmouta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdint.h> //////////////////////to delete
//#define malloc(...) NULL


void	ft_strjoin_helper(char *s1, char *s2, char *dest)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	dest = (char *)malloc((ft_lnlen(s1) + ft_lnlen(s2) + 1)); // * (ft_lnlen(s1) + ft_lnlen(s2) + 1) * sizeof(char)
	if (!dest)
	{
		free(s1);                  //////////changed
		return (NULL);
	}
	ft_strjoin_helper(s1, s2, dest);
	free(s1);
	return (dest);
}

char	*ft_lnalloc(int fd, char *s)
{
	char	*buff;
	char	*tmp;
	ssize_t	dim;
	
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	dim = 1;
	while (!(ft_strchr(s, '\n')) && dim > 0)
	{
		dim = read(fd, buff, BUFFER_SIZE);
		if (dim == 0)
			break ;
		else if (dim == -1)
			return (free(buff), NULL);
		buff[dim] = '\0';
		tmp = ft_strjoin(s, buff);
		if(!tmp)         /////////////changed
		{
			free(buff);
			free(s);
			return (NULL);
		}
		s = tmp;
		if (dim < BUFFER_SIZE)
			break ;
	}
	return (free(buff), s);
}

char	*ft_lnnext(char *str)
{
	char	*new;
	int		i;
	int	hasnl;

	hasnl = 0;
	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if(str[i] == '\n')
		hasnl = 1;
	new = (char *)malloc(sizeof(char) * (i + hasnl + 1));
	if (!new)
		return (NULL);
	ft_bzero(new, (i + hasnl + 1));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_lnrem(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_lnlen(line) - i));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
	{
		str[j++] = line[i++];
	}
	str[j] = '\0';
	free(line);
	return (str);
}
