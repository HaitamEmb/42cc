#include "ft_printf.h"

int   ft_hex_len(unsigned int nb)
{
  int   len;

  len = 0;
  while (nb != 0)
  {
    len++;
    nb = nb / 16;
  }
  return (len);
}

void ft_hex(unsigned int nb, const char format)
{
  if(nb >= 16)
  {
    ft_hex(nb / 16, format);
    ft_hex(nb % 16, format);
  }
  else
  {
    if (nb <= 9)
    {
      ft_putchar(nb + '0');
    }
    else
    {
      if (format == 'x')
        ft_putchar((nb - 10) + 'a');
      if (format == 'X')
        ft_putchar((nb - 10) + 'A');
    }
  }
}

int ft_puthex(unsigned int nb, const char format)
{
  if (nb == 0)
    return (write(1, "0", 1));
  else
    ft_hex(nb, format);
  return(ft_hex_len(nb));
}
