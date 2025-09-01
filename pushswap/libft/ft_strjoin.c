#include "libft.h"

char  *ft_strjoin(char const *s1, char const *s2)
{
  char *dest;
  size_t s1len;
  size_t s2len;
  size_t size;
  int   i;
  int   j;

  i=0;
  j=0;

  if (!s1 || !s2)
    return (NULL);
  s1len = ft_strlen(s1);
  s2len = ft_strlen(s2);

  size = s1len + s2len;
  
  dest = (char *)malloc(sizeof(char) * (size + 1));
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
  return (dest);
}