void ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
  del (&((*alst)->content) ,(*alst)->content_size);
  free (*alst);
  ft_memdel (alst);
}
