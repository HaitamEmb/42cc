#include "push_swap.h"

static int  ft_nbrcmp(const char *s1, const char *s2)
{
  int i;
  int j;

  i = 0;
  j = i;
  if (s1[i] == '+')
  {
    if (s2[j] != '+')
      i++;
  }
  else
  {
    if (s2[j] == '+')
      j++;
  }
  while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
  {
    i++;
    j++;
  }
  return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
static int  arg_is_nbr(char *av)
{
  int i;

  i = 0;
  if ((av[i] == '+' || av[i] == '-') && av[i + 1] != '\0')
    i++;
  while (av[i] && ft_isdigit(av[i]))
    i++;
  if (av[i] != '\0' && !ft_isdigit(av[i]))
    return (0);
  return (1);
}

static  int duplicated(char **av)
{
  int i;
  int j;

  i = 1;
  while (av[i])
  {
    j = 1;
    while(av[j])
    {
      if (j != i && ft_nbrcmp(av[i], av[j]) == 0)
        return (1);
      j++;
    } 
    i++;
  }
  return (0);
}

static int null_arg(char *av)
{
  int i;

  i = 0;
  if ((av[i] == '+' || av[i] == '-'))
    i++;
  while (av[i] && av[i] == '0')
    i++;
  if (av[i] != '\0')
    return (0);
  return (1);
}

int correct_input(char **av)
{
  int i;
  int skip_zeros;

  skip_zeros = 0;
  i = 1;
  while (av[i])
  {
    if (!arg_is_nbr(av[i]))
      return (0);
    skip_zeros += null_arg(av[i]);
    i++;
  }
  if (skip_zeros > 1)
    return 0;
  if (duplicated(av))
    return (0);
  return (1);
}