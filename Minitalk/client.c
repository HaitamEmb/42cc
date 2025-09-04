#include <signal.h>

void	kill_func(int pid, unsigned char octet)
{
	int	i;
	unsigned char	bit;

	bit = octet;
	i = 8;
	while (i-- > 0)
	{
		bit = octet >> i;
		if (bit % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}
int	main(int ac, char **av)
{
	int	id;
	char	*str;
	int	i;

	if (ac != 3)
	{
		ft_printf("");
		return (0);
	}
	id = ft_atoi(av[1]);
	str = av[2];
	i = 0;
	while(str[i])
	{
		kill_func(id, str[i]);
		i++;
	}
	ft_printf("");
	return (0);
}