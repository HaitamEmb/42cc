#include "libft.h"

int   ft_isdigit(char c)
{
    if (c >= 48 && c <= 57)
    {
      return 1;
    }
    return 0;
}

/*
#include <stdio.h>

int   main()
{
  char c = '9';
  if (ft_isdigit(c))
  {
    printf("good2");
  }
  return 0;
}
*/