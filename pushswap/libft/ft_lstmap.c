#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
  t_list *new;
  t_list *node;
  void  *new_content;

  if (!lst || !f)
    return (NULL);
  new = NULL;
  while(lst)
  {
    new_content = f(lst->content);
    node = ft_lstnew(new_content);
    if(!node)
    {
      ft_lstclear(&node, del);
      return (NULL);
    }

    ft_lstadd_back(&new, node);
    lst = lst->next;
  }
  return (new);
} 