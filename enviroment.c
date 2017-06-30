/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxwin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 22:27:08 by ksaetern          #+#    #+#             */
/*   Updated: 2017/04/30 22:27:12 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*storing pixel coordinates with the mid point of your grid at the (0,0) mark of your window */
/*comment out rotation and translation to see this */
t_points		**ft_makecartesian(t_env *fdf, t_map *m)
{
	t_points	**c;

	if (!(c = (t_points **)malloc(sizeof(t_points *) * (m->h + 1))))
		return (NULL);
	m->midx = m->w / 2;
	m->midy = m->h / 2;
	while (fdf->i < m->h)
	{
		c[fdf->i] = (t_points *)malloc(sizeof(t_points) * (m->w + 1));
		fdf->j = 0;
		while (fdf->j < m->w)
		{
			c[fdf->i][fdf->j].x = ((fdf->j - m->midx) * fdf->gap);
			c[fdf->i][fdf->j].y = ((fdf->i - m->midy) * fdf->gap);
			c[fdf->i][fdf->j].z = m->map[fdf->i][fdf->j] * 5;
			c[fdf->i][fdf->j].rawz = m->map[fdf->i][fdf->j];
		 	fdf->j++;
		}
		fdf->i++;
	}
	c[fdf->i] = NULL;
	printf("x/width = %d, y/height = %d\n", m->w, m->h);
	printf("midx = %d, midy = %d\n", m->midx, m->midy);
	printf("(0,0) = (%f, %f)\n", c[0][0].y, c[0][0].x);
	printf("(0,1) = (%f, %f)\n", c[0][1].y, c[0][1].x);
	printf("(1,0) = (%f, %f)\n", c[1][0].y, c[1][0].x);
	printf("(%d,%d) = (%f, %f)\n", m->midy, m->midx, c[m->midy][m->midx].y, c[m->midy][m->midx].x);
	printf("(9,14) = (%f, %f)\n", c[9][14].y, c[9][14].x);
	return (c);
}

void			ft_hooked(t_hooks **hooks)
{
	/* Hooks dont do anything but its there to give you an idea of where to use it and how for bonus */
	(*hooks)->zr = 1;
	(*hooks)->yr = 1;
	(*hooks)->xr = 1;
	(*hooks)->xt = 0.0;
	(*hooks)->yt = 0.0;
	(*hooks)->zs = 0;
	printf("hooks finished\n");
}

void			ft_populate(t_env **fdf, t_map *m)
{
	(*fdf)->hooks = (t_hooks *)malloc(sizeof(t_hooks));
	ft_hooked(&(*fdf)->hooks);
	(*fdf)->x1 = 0;
	(*fdf)->y1 = 0;
	(*fdf)->x2 = 0;
	(*fdf)->y2 = 0;
	(*fdf)->hmax = m->hmax;
	(*fdf)->hmin = 0;
	(*fdf)->w = m->w;
	(*fdf)->h = m->h;
	(*fdf)->big = m->w > m->h ? m->w : m->h;
	(*fdf)->gap = m->w > m->h ? 700 / (m->w) : 700 / (m->h);
	(*fdf)->m = 0;
	(*fdf)->rise = 0;
	(*fdf)->run = 0;
	(*fdf)->max = 800 + (*fdf)->gap * ((*fdf)->big);
	(*fdf)->maxside = (*fdf)->max - 300;
	printf("Dimension = %f x %f\nPixel gap = %d\n", (*fdf)->max, (*fdf)->maxside, (*fdf)->gap);
	(*fdf)->i = 0;
	(*fdf)->j = 0;
	(*fdf)->cart = ft_makecartesian(*fdf, m);
	(*fdf)->mlx = mlx_init();
	(*fdf)->win = mlx_new_window((*fdf)->mlx, (*fdf)->max, (*fdf)->maxside, "FDF");
}

t_env			*ft_makeenviroment(t_map *m)
{
	t_env		*fdf;

	fdf = (t_env *)ft_memalloc(sizeof(t_env));
	ft_populate(&fdf, m);
	return (fdf);
}
