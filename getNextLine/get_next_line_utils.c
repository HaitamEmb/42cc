#include "get_next_line.h"

size_t ft_lnlen(char *str)
{
  size_t   i;

  i = 0;
  if (!str)
    return(0);
  while(str[i])
  {
    i++;
  }
  return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while(s[i])
	{
		if(s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char  *ft_strjoin(char *s1, char *s2)
{
  char *dest;
  size_t size;
  size_t   i;
  size_t   j;

  i=0;
  j=0;

  if (!s1)
  {
    s1 = (char *)malloc(1);
    if(!s1)
      return (NULL);
    s1[0] = '\0';
  }
  if (!s2)
    return (NULL);
  size =  ft_lnlen(s1) + ft_lnlen(s2);
  dest = (char *)malloc((size + 1) * sizeof(char));
  if (!dest)
    return (NULL);  

  while(s1[i])
  {
    dest[i] = s1[i];
    i++;
  }
  while(s2[j])
  {
    dest[i] = s2[j];
    i++;
    j++;
  }
  dest[i] = '\0';
  free(s1);
  return (dest);
}
char  *ft_lnalloc(int fd, char *s)
{
  char  *buff;
  ssize_t dim;

  buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
  if(!buff)
    return (NULL);
  dim = 1;
  while(!(ft_strchr(s, '\n')) && dim > 0)
  {
    dim = read(fd, buff, BUFFER_SIZE);
    if(dim == -1)
    {
      free(buff);
      return (NULL);
    }
    buff[dim] = '\0';
    s = ft_strjoin(s, buff);
  }
  free(buff);
  return(s);
}
char  *ft_lnnext(char *str)
{
  char  *new;
  int   i;

  i = 0;
  while(str[i] && str[i] != '\n')
    i++;
  new = (char *)malloc(sizeof(char) * (i + 2));
  if(!new)
    return(NULL);
  i = 0;
  while(str[i] && str[i] != '\n')
  {
    new[i] = str[i];
    i++;
  }
  if(str[i] == '\n')
    new[i] = str[i];
    i++;
  new[i] = '\0';
  return(new);
}
char  *ft_lnrem(char *line)
{
  char   *str;
  int	i;
  int	j;

  i = 0;
  while(line[i] && line[i] != '\n')
	  i++;
  if(!line[i])
  {
	  free(line);
	  return (NULL);
  }
  str = (char *)malloc(sizeof(char) * (ft_lnlen(line) - i));
  if(!str)
	  return (NULL);
  i++;
  j = 0;
  while(line[i])
  {
	str[j] = str[i];
	j++;
	i++;
  }
  str[j] = '\0';
  free(line);
  return(str);
}
