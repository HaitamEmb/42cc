#include "push_swap.h"

static void push(t_stack **s, t_stack **d)
{
  t_stack *tmp;

  if (*s == NULL)
    return;
  tmp = (*s)->next;
  (*s)->next = *d;
  *d = *s;
  *s = tmp;
}

void do_pa(t_stack  **a, t_stack  **b)
{
  push(b, a);
  ft_putstr("pa\n");
}

void  do_pb(t_stack **a, t_stack  **b)
{
  push(a, b);
  ft_putstr("pb\n");
}