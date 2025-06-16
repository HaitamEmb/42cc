#include "get_next_line.h"


char  *get_next_line(int fd)
{
  char  *dest;
  static char *str;
  
  if(BUFFER_SIZE <= 0 || fd < 0)
	  return (NULL);
  str = ft_lnalloc(fd, str);
  if(!str)
	  return (NULL);
  dest = ft_lnnext(str);
  str = ft_lnrem(str);
  return (dest);
}

int	main()
{
	char	*str;
	int	i;
	int	fd;
	
	fd = open("test.txt", O_RDONLY);
	i = 1;
	while (i < 5)
	{
		str = get_next_line(fd);
		printf("line [%02d], %s, i, str");
		free(str);
		i++;
	}
	close(fd);
	return(0);
}
