#ifndef FT_PRINT_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

int   ft_putchar_l(char c);
int   ft_putstr_l(char *str);
int   ft_putnbr(int nbr);
int   ft_printf(const char *spec, ...);
int   ft_convert(va_list args, const char format);
int   ft_hex_len(unsigned int nb);
void  ft_hex(unsigned int nb, const char format);
int   ft_puthex(unsigned int nb, const char format);
int   ft_ptrlen(unsigned long long ptr);
int   ft_putptr(unsigned long long ptr);
int   ft_ptr(unsigned long long ptr);
int   ft_unlen(unsigned int s);
char  *ft_utoa(unsigned int nbr);
int   ft_punsigned(unsigned int nbr);

#endif