#include "ft_printf.h"

int ft_putchar_l(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr_l(char *str)
{
  int   i;

  i = 0;
  if (!str)
  {
      write(1, "Null", 4);
      return(4);
  }
  while(str[i])
  {
    ft_putchar(str[i]);
    i++;
  }
  return (i);
}

int ft_putnbr(int nbr)
{
  int   len;
  char  *str;

  str = ft_itoa(nbr);
  len = ft_putstr_l(str);

  free(str);
  return (len);
}