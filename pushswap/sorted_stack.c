#include "push_swap.h"

int is_sorted(t_stack *stack)
{
  while(stack->next != NULL)
  {
    if(stack->value > stack->next->value)
      return (0);
    stack = stack->next;
  }
  return (1);
}

t_stack *ft_stacklast(t_stack *lst)
{
  if (!lst)
    return (NULL);
  while(lst -> next != NULL)
    lst = lst -> next;
  return (lst);
}

void ft_stackaddback(t_stack **lst, t_stack *new)
{
  t_stack *tmp;

  if(!*lst)
  {
    *lst = new;
    return;
  }

  tmp = ft_stacklast(*lst);
  tmp -> next = new;
}

int     ft_stacksize(t_stack *lst)
{
  int size;

  size = 0;
  while(lst != NULL)
  {
    size++;
    lst = lst -> next;
  }
  return (size);
}