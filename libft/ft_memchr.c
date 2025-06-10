#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)str)[index] == (unsigned char)c)
			return (((unsigned char *)str) + index);
		index++;
	}
	return (NULL);
}