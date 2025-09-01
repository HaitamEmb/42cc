#include "push_swap.h"

int nbr_abs(int nb)
{
  if (nb < 0)
    nb *= -1;
  return (nb);
}

void  ft_putstr(char *str)
{
  int i;

  i = 0;
  while(str[i])
    write(1,&str[i++],1);
}

void  free_stack(t_stack  **stack)
{
  t_stack *tmp;

  if (!stack || !(*stack))
    return ;
  while (*stack)
  {
    tmp = (*stack)->next;
    free(*stack);
    *stack = tmp;
  }
  *stack = NULL;
}

void  exit_error(t_stack **a, t_stack **b)
{
  if (a == NULL || *a != NULL)
    free_stack(a);
  if (b == NULL || *b != NULL)
    free_stack(b);
  write(2, "Error\n", 6);
  exit (1);
}

long int  ft_atol(const char *str)
{
  long int  nb;
  int i;
  int sign;

  nb = 0;
  sign = 1;
  i = 0;
  if (str[i] == '+')
    i++;
  else if (str[i] == '-')
  {
    sign *= -1;
    i++;
  }
  while (ft_isdigit(str[i]))
  {
    nb = (nb * 10) + (str[i] - '0');
    i++;
  }
  return (nb * sign);
}