void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
  t_list tmp;
  t_list todel;
  
  tmp = alst;
  while (tmp != NULL)
    {
      if (del != NULL)
	del(&(*tmp->content), (*tmp).content_size);
      todel = tmp->next;
      free(*tmp);
      tmp = todel;
    }
  *alst = NULL;
}
