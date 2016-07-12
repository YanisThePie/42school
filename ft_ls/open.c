/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 04:27:34 by yismail           #+#    #+#             */
/*   Updated: 2016/07/12 03:02:08 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #include "ft_ls.h"

int main (int argc, char **argv)
{
    (void)argc;
    struct s_env env;

    ft_bzero(&env, sizeof(struct s_env));
    if (argv[1] == NULL) // no arg and no path
    {
        no_arg(&env);
        return(0);
    }
    else
    {
		env.argv = argv;
        if (argv[1][0] != '-') //no arg but path
        {
            env.dir = opendir(argv[1]);
            read_the_path(argv[1], "0", env);
        }
        if (argv[1][0] == '-') // arg
            how_many_flags(argv, &env);
    }
}
