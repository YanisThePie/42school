/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:20:19 by yismail           #+#    #+#             */
/*   Updated: 2015/11/26 20:29:21 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int ft_strlen (char *c)
{
	int cpt;
  
	cpt = 0;
	while (*c != '\0')
    {
		c++;
		cpt++;
    }
	return (cpt);
}

char *ft_strncpy (char *dest, char *src, size_t n)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(src);
	  while (src[i] != '\0' && i <= n && i <= j)
	{
		dest[i] = src[i];
		i++;
	}
	  while (src[i] == '\0' && dest[i])
      {
        dest[i] = '\0';
          i++;
      }
	  return(dest);
}
