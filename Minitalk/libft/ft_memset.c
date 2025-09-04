#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)dest;
	while (len > 0)
	{
		ptr [len - 1] = ch;
		len--;
	}
	return (dest);
}