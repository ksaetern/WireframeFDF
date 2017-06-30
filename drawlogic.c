/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 00:10:56 by ksaetern          #+#    #+#             */
/*   Updated: 2017/06/03 00:10:58 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_setpointsdown(t_env **fdf, int i, int j, t_hooks *hooks)
{
	if (i + 1 < (*fdf)->h)
	{
		(*fdf)->x1 = round((*fdf)->cart[i][j].x) + hooks->xt;
		(*fdf)->y1 = round((*fdf)->cart[i][j].y) + hooks->yt;
		(*fdf)->x2 = round((*fdf)->cart[i + 1][j].x) + hooks->xt;
		(*fdf)->y2 = round((*fdf)->cart[i + 1][j].y) + hooks->yt;
		(*fdf)->curr_z = (*fdf)->cart[i][j].rawz;
		(*fdf)->next_z = (*fdf)->cart[i + 1][j].rawz;
		(*fdf)->rise = (*fdf)->y2 - (*fdf)->y1;
		(*fdf)->run = (*fdf)->x2 - (*fdf)->x1;
	}
}

void			ft_drawdown(t_env *fdf, t_bresen **breezy, t_hooks *hooks)
{
	fdf->i = 0;
	while (fdf->i < fdf->h)
	{
		fdf->j = 0;
		while (fdf->j < fdf->w)
		{
			ft_setpointsdown(&fdf, fdf->i, fdf->j, hooks);
			if (fdf->run == 0 && fdf->i + 1 < fdf->h)
				ft_slopestraight(fdf);
			else
			{
				fdf->m = fdf->rise / fdf->run;
				(*breezy)->adjust = fdf->m >= 0 ? 1 : -1;
				(*breezy)->offset = 0;
				(*breezy)->threshold = 0.5;
				if (fdf->m <= 1 && fdf->m >= -1)
					ft_slopegradual(fdf, *breezy);
				else
					ft_slopesharp(fdf, *breezy);
			}
			fdf->j++;
		}
		fdf->i++;
	}
}

void			ft_setpointsright(t_env **fdf, int i, int j, t_hooks *hooks)
{
	if (j + 1 < (*fdf)->w)
	{
		(*fdf)->x1 = round((*fdf)->cart[i][j].x) + hooks->xt;
		(*fdf)->y1 = round((*fdf)->cart[i][j].y) + hooks->yt;
		(*fdf)->x2 = round((*fdf)->cart[i][j + 1].x) + hooks->xt;
		(*fdf)->y2 = round((*fdf)->cart[i][j + 1].y) + hooks->yt;
		(*fdf)->curr_z = (*fdf)->cart[i][j].rawz;
		(*fdf)->next_z = (*fdf)->cart[i][j + 1].rawz;
		(*fdf)->rise = (*fdf)->y2 - (*fdf)->y1;
		(*fdf)->run = (*fdf)->x2 - (*fdf)->x1;
	}
}

void			ft_drawright(t_env *fdf, t_bresen **b, t_hooks *hooks)
{
	fdf->i = 0;
	while (fdf->i < fdf->h)
	{
		fdf->j = 0;
		while (fdf->j < fdf->w)
		{
			ft_setpointsright(&fdf, fdf->i, fdf->j, hooks);
			if (fdf->run == 0 && fdf->j + 1 < fdf->h)
				ft_slopestraight(fdf);
			else
			{
				fdf->m = fdf->rise / fdf->run;
				(*b)->adjust = fdf->m >= 0 ? 1 : -1;
				(*b)->offset = 0;
				(*b)->threshold = 0.5;
				if (fdf->m <= 1 && fdf->m >= -1)
					ft_slopegradual(fdf, *b);
				else
					ft_slopesharp(fdf, *b);
			}
			fdf->j++;
		}
		fdf->i++;
	}
}
/* rotation(x,y,or z), translation, drawright, drawdown*/
/* you can turn off each ft by commenting it out to see what each one does */
/* rotation first then translate, try doing it the other way around to see your shit f**kd :) */
void			ft_draw(t_env *fdf, t_hooks *hooks)
{
	int			x;
	int			y;
	t_bresen	*breezy;

	x = 0;
	y = 0;
	breezy = (t_bresen *)malloc(sizeof(t_bresen));
	ft_rotate(fdf, hooks);
	ft_translate(&fdf, hooks);
	ft_drawright(fdf, &breezy, hooks);
	ft_drawdown(fdf, &breezy, hooks);
}
