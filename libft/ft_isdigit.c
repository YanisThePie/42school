int ft_isdigit (int c)
{
  if (c >= 48 && c <= 57)
    return (1);

  if (c < 48 && c > 57)
    return (0);
}
