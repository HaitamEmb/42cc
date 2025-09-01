#include "push_swap.h"

t_stack *get_stack_tail(t_stack *stack)
{
  return (ft_stacklast(stack));
}

t_stack *get_stack_before_tail(t_stack *stack)
{
  while(stack && stack->next && stack->next->next != NULL)
    stack = stack->next;
  return (stack);
}

int get_stack_size(t_stack *stack)
{
  return (ft_stacksize(stack));
}

void stack_add_bottom(t_stack **stack, t_stack *new)
{
  ft_stackaddback(stack, new);
}

t_stack *stack_new(int value)
{
  t_stack *new;
  new = malloc(sizeof(t_stack));
  if(!new)
    return (NULL);
  new->value = value;
  new->index = 0;
  new->pos = -1;
  new->target_pos = -1;
  new->cost_a = -1;
  new->cost_b = -1;
  new->next = NULL;
  return (new);
}