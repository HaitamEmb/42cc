#include "libft.h"

void  *ft_calloc(size_t nmemb, size_t size)
{
  void  *arr;

  arr = (void *)malloc(nmemb * size);
  if (!arr)
    return (NULL);
  ft_bzero(arr, (nmemb * size));
  return (arr);
}
/*return unique pointer*/