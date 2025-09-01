#include "push_swap.h"

int max_index(t_stack *stack)
{
  int index;
  index = stack->index;
  while(stack)
  {
    if (stack->index > index)
      index = stack->index;
    stack = stack->next;
  }
  return (index);
}

void tiny_sort(t_stack **stack)
{
  int max;

  if(is_sorted(*stack))
    return;
  max = max_index(*stack);
  if ((*stack)->index == max)
    do_ra(stack);
  else if ((*stack)->next->index == max)
    do_rra(stack);
  if ((*stack)->index > (*stack)->next->index)
    do_sa(stack);
}