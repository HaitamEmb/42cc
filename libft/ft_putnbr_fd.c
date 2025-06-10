#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = n;
	if (l > 2147483647 || l < -2147483648)
		return ;
	if (l < 0)
	{
		l = l * -1;
		ft_putchar_fd('-', fd);
	}
	if (l >= 10)
	{
		ft_putnbr_fd(l / 10, fd);
		l = l % 10;
	}
	if (l < 10)
	{
		ft_putchar_fd((l + '0'), fd);
	}
}