#include "libft.h"

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
  t_list *tmp;
  t_list *tmp2;
  t_list *ret;

  if (!lst || !f)
    return (NULL);
  tmp2 = f(lst);
  if ((ret = ft_lstnew(tmp2->content, tmp2->content_size)))
    {
      tmp = ret;
      lst = lst->next;
      while (lst)
	{
	  tmp2 = f(lst);
	  if (!(tmp->next = ft_lstnew(tmp2->content, tmp2->content_size)))
	    return (NULL);
	  tmp = tmp->next;
	  lst = lst->next;
	}
    }
  return (ret);
}
