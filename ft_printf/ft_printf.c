#include "ft_printf.h"

int  ft_convert(va_list args, const char format)
{
  int pchar;

  pchar = 0;
  if(format == 'c')
    pchar += ft_putchar_l(va_arg(args, int));
  else if (format == 's')
    pchar += ft_putstr_l(va_arg(args, char *));
  else if (format == 'p')
    pchar += ft_putptr(va_arg(args, unsigned long long)); //to check
  else if (format == 'd' || format == 'i')
    pchar += ft_putnbr(va_arg(args, int));
  else if (format == 'u')
    pchar += ft_punsigned(va_arg(args, unsigned int));
  else if (format == 'x' || format == 'X')
    pchar += ft_puthex(va_arg(args, unsigned int), format);
  else if (format == '%')
    pchar += ft_putchar_l('%');
  return (pchar);

}
int   ft_printf(const char *format, ...)
{
  va_list  args;
  int   pchar;
  int   i;
  i = 0;
  pchar = 0;
  va_start(args, format);

  while(format[i])
  {
    if(format[i] == '%')
    {
      pchar += ft_convert(args, format [i+ 1]);
      i++;
    }
    else
      pchar += ft_putchar_l(format[i]);
    i++;
  }
  va_end(args);
  return(pchar);
}