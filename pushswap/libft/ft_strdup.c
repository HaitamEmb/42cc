#include "libft.h"

char  *ft_strdup(char *str)
{
  size_t  size;
  char *dest;
  
  size = ft_strlen(str);
  dest = (char *)malloc(sizeof(char) * (size + 1));
  
  if (dest == NULL)
    return (0);
  
  ft_memcpy(dest, str, size);
  dest[size] = '\0';
  return (dest);
}