#include "push_swap.h"

void  push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
  if (stack_size == 2 && !is_sorted(*stack_a))
    do_sa(stack_a);
  else if (stack_size == 3)
    tiny_sort(stack_a);
  else if (stack_size > 3 && !is_sorted(*stack_a))
    sort(stack_a, stack_b);
}

int main(int ac, char **av)
{
  t_stack *a;
  t_stack *b;
  int stack_size;

  if (ac < 2)
    return (0);
  if (!correct_input(av))
    exit_error(NULL, NULL);
  b = NULL;
  a = fill_stack(ac, av);
  stack_size = get_stack_size(a);
  assign_index(a, stack_size + 1);
  push_swap(&a, &b, stack_size);
  free_stack(&a);
  free_stack(&b);
  return (0);
}