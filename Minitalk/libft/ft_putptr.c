#include "ft_printf.h"

int ft_ptrlen(unsigned long long ptr)
{
  int len;

  len = 0;
  while(ptr != 0)
  {
    len++;
    ptr = ptr / 16;
  }
  return (len);
}

void  ft_ptr(unsigned long long ptr)
{
  if (ptr >= 16)
  {
    ft_ptr(ptr / 16);
    ft_ptr(ptr % 16);
  }
  else
  {
    if (ptr <= 9)
      ft_putchar((ptr + '0'));
    else
      ft_putchar((ptr - 10 + 'a'));
  }
}

int   ft_putptr(unsigned long long ptr)
{
  int pchar;

  pchar = 0;
  pchar += write(1, "0x", 2);
  if(ptr == 0)
    pchar += write(1, "0", 2);
  else
  {
    ft_ptr(ptr);
    pchar += ft_ptrlen(ptr);
  }
  return (pchar);
}