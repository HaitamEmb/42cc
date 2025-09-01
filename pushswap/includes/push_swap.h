#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
//libft
#include "../libft/libft.h"

typedef struct s_stack
{
  int value;
  int index;
  int cost_a;
  int cost_b;
  int pos;
  int target_pos;
  struct s_stack *next;
} t_stack;

//input check
int correct_input(char **av);
//init
t_stack *fill_stack(int ac, char **av);
void  assign_index(t_stack  *stack_a, int stack_size);
//char **p_split(char *str, char c);
//stack
t_stack *get_stack_tail(t_stack *stack);
t_stack *get_stack_before_tail(t_stack *stack);
t_stack *stack_new(int value);
void stack_add_bottom(t_stack **stack, t_stack *new);
int get_stack_size(t_stack *stack);
//sort
int is_sorted(t_stack *stack);
void tiny_sort(t_stack **stack);
void  sort(t_stack **stack_a, t_stack **stack_b);
//pos
int get_low_index_pos(t_stack **s);
void  get_target_pos(t_stack **a, t_stack **b);
//cost
void  get_cost(t_stack **stack_a, t_stack **stack_b);
void  do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
//moves
void  do_move(t_stack **a, t_stack  **b, int cost_a, int cost_b);
//commands
void do_pa(t_stack  **a, t_stack  **b);
void  do_pb(t_stack **a, t_stack  **b);
void do_sa(t_stack **stack_a);
void  do_rra(t_stack **stack_a);
void  do_rrb(t_stack **stack_b);
void  do_rrr(t_stack **stack_a, t_stack **stack_b);
void do_ra(t_stack **stack_a);
void do_rb(t_stack **stack_b);
void do_rr(t_stack **stack_a, t_stack **stack_b);
void  do_sb(t_stack **stack_b);
void  do_ss(t_stack **stack_a, t_stack **stack_b);
//utils & errors
void  free_stack(t_stack  **stack);
void  exit_error(t_stack **a, t_stack **b);
void  ft_putstr(char *str);
long int  ft_atol(const char *str);
int nbr_abs(int nb);
t_stack *ft_stacklast(t_stack *lst);
void ft_stackaddback(t_stack **lst, t_stack *new);
int     ft_stacksize(t_stack *lst);
#endif