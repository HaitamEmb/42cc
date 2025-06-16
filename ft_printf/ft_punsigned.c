#include "ft_printf.h"

int ft_unlen(unsigned int s)
{
  int len;

  len = 0;
  while(s != 0)
  {
    len++;
    s = s / 10;
  }
  return (len);
}

char  *ft_utoa(unsigned int nb)
{
  char *s;
  int   len;

  len = ft_unlen(nb);
  s = (char *)malloc((len + 1) * sizeof(char *));
  if (!s)
    return (NULL);
  s[len] = '\0';
  while(nb != 0)
  {
    s[len - 1] = nb % 10 + '0';
    nb = nb / 10;
    len--;
  }
  return (s);
}
int ft_punsigned(unsigned int nb)
{
  int   len;
  char  *s;

  len = 0;
  if (nb == 0)
    len += write(1, "0", 1);
  else
  {
    s = ft_utoa(nb);
    len += ft_putstr(s);
    free(s);
  }
  return (len);
}