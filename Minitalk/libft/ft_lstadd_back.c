#include "libft.h"

void ft_lstaddback(t_list **lst, t_list *new)
{
  t_list *tmp;

  if(!*lst)
  {
    *lst = new;
    return;
  }

  tmp = ft_lstlast(*lst);
  tmp -> next = new;
}