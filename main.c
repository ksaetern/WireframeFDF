/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 15:54:51 by ksaetern          #+#    #+#             */
/*   Updated: 2017/04/27 15:54:58 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int				my_key_funct(int keycode, void *param)
{
	ft_putstr("Keyevent: ");
	ft_putendl(ft_itoa(keycode));
	if (keycode == 53)
		exit(0);
	return (0);
}



int				main(int ac, char **av)
{
	t_map		*m;
	t_env		*fdf;
	t_hooks		*hooks;

	if (ac != 2)
		ft_error("Error: Map Arg wrong");
	ft_parse(av[1]);
	if (!(m = (t_map *)malloc(sizeof(t_map))))
		ft_error("Error: Malloc");
	ft_store(av[1], m);
	fdf = ft_makeenviroment(m);
	ft_draw(fdf, fdf->hooks);
	mlx_key_hook(fdf->win, my_key_funct, 0);
	mlx_loop(fdf->mlx);
	return (0);
}
