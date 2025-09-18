#include <signal.h>
#include "../libft/libft.h"
void	do_act(int siguser)
{
	static unsigned char	buff;
	static int	i = 0;

	buff |= (siguser == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", buff);
		i = 0;
		buff = 0;
	}
	else
		buff <<= 1;
}
int main(int ac, char **av)
{
  ft_printf("PID: %i\n", getpid());
  signal(SIGUSR2, do_act);
  signal(SIGUSR1, do_act);
  while (1)
    pause();
  return (0);  
}
