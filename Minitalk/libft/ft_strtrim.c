#include "libft.h"

int   ft_ccheck(char const c, char const *set)
{
  int   i;
  i = 0;

  while(set[i])
  {
    if (set[i] == c)
      return (1);
    i++;
  }
  return (0);
}
char  *ft_strtrim(char const *s1, char const *set)
{
  char  *dest;
  size_t size;

  if (!s1 || !set)
    return (NULL);

  while(*s1)
  {
    if (ft_ccheck(*s1, set))
      s1++;
    else
      break;
  }
  size = ft_strlen(s1);

  while(size != 0)
  {
    if(ft_ccheck(s1[size - 1], set))
      size--;
    else
      break;
  }
  dest = (char *)malloc(size * (sizeof(char) + 1));
  if(!dest)
    return (NULL);
  ft_strlcpy(dest, s1, size + 1);
  return (dest);
}