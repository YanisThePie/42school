/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:06:52 by yismail           #+#    #+#             */
/*   Updated: 2015/11/26 21:07:53 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int main (void)
{
	char *c;
	c = ft_strnstr ("michade", "ad", 6);
	printf ("%s", c);
}