#include  "push_swap.h"

static void get_pos(t_stack **s)
{
  t_stack *tmp;
  int i;

  tmp = *s;
  i = 0;
  while(tmp)
  {
    tmp->pos = i;
    tmp = tmp->next;
    i++;
  }
}

int get_low_index_pos(t_stack **s)
{
  t_stack *tmp;
  int l_index;
  int l_pos;

  tmp = *s;
  l_index = INT_MAX;
  get_pos(s);
  l_pos = tmp->pos;
  while(tmp)
  {
    if (tmp->index < l_index)
    {
      l_index = tmp->index;
      l_pos = tmp->pos;
    }
    tmp = tmp->next;
  }
  return (l_pos);
}

static int get_target(t_stack **a, int index_b, int target_index, int target_pos)
{
  t_stack *tmpa;

  tmpa = *a;
  while (tmpa)
  {
    if (tmpa->index > index_b && tmpa->index < target_index)
    {
      target_index = tmpa->index;
      target_pos = tmpa->pos;
    }
    tmpa = tmpa->next;
  }
  if (target_index != INT_MAX)
    return (target_pos);
  tmpa = *a;
  while (tmpa)
  {
    if (tmpa->index < target_index)
    {
      target_index = tmpa->index;
      target_pos = tmpa->pos;
    }
    tmpa = tmpa->next;
  }
  return (target_pos);
}

void  get_target_pos(t_stack **a, t_stack **b)
{
  t_stack *tmpb;
  int target_pos;

  tmpb = *b;
  get_pos(a);
  get_pos(b);
  target_pos = 0;
  while (tmpb)
  {
    target_pos = get_target(a, tmpb->index, INT_MAX, target_pos);
    tmpb->target_pos = target_pos;
    tmpb = tmpb->next;
  }
  
}