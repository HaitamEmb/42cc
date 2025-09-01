#include "push_swap.h"

static void push_but_three(t_stack **stack_a, t_stack **stack_b)
{
  int stack_size;
  int pushed;
  int i;

  stack_size = get_stack_size(*stack_a);
  pushed = 0;
  i = 0;
  while (stack_size > 6 && i < stack_size && pushed < stack_size / 3)
  {
    if((*stack_a)->index <= stack_size / 2)
    {
      do_pb(stack_a, stack_b); //add
      pushed++;
    }
    else
      do_ra(stack_a);
    i++;
  }
  while (stack_size - pushed > 3)
  {
    do_pb(stack_a, stack_b);
    pushed++;
  }
}

static void shift_stack(t_stack **stack_a)
{
  int lowest_pos;
  int stack_size;

  stack_size = get_stack_size(*stack_a); //add
  lowest_pos = get_low_index_pos(stack_a); //add
  if (lowest_pos > stack_size / 2)
  {
    while(lowest_pos < stack_size)
    {
      do_rra(stack_a); //add
      lowest_pos++;
    }
  }
  else
  {
    while (lowest_pos > 0)
    {
      do_ra(stack_a);
      lowest_pos--;
    }
  }

}

void  sort(t_stack **stack_a, t_stack **stack_b)
{
  push_but_three(stack_a, stack_b);
  tiny_sort(stack_a);
  while(*stack_b)
  {
    get_target_pos(stack_a, stack_b);
    get_cost(stack_a, stack_b);
    do_cheapest_move(stack_a, stack_b);
  }
  if(!is_sorted(*stack_a))
    shift_stack(stack_a);
}