void ft_lstadd(t_list **alst, t_list *new)
{
  t_list tmp;

  tmp = new;
  if (alst != NULL && new != NULL)
    { 
      tmp->next = *alst;
      *alst = new;
}
