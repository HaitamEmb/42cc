#include "libft.h"

char  *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  char  *new;
  size_t  size;
  unsigned int  i;

  if(!s)
    return (0);

  size = ft_strlen(s);
  new = (char *)malloc(sizeof(char) * (size + 1));
  if (!new)
    return (0);
  new[size] = '\0';
  i = 0;
  while(s[i])
  {
    new[i] = f(i, s[i]);
    i++;
  }
  return (new);
  }