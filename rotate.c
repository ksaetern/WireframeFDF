/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 01:46:55 by ksaetern          #+#    #+#             */
/*   Updated: 2017/06/03 01:46:57 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* .7854 radians = 45 degrees*/ 
void	ft_zrotate(t_env **f)
{
	float	x;
	float	y;

	(*f)->i = 0;
	while ((*f)->i < (*f)->h)
	{
		(*f)->j = 0;
		while ((*f)->j < (*f)->w)
		{
			x = (*f)->cart[(*f)->i][(*f)->j].x;
			y = (*f)->cart[(*f)->i][(*f)->j].y;
			(*f)->cart[(*f)->i][(*f)->j].x = x * cos(0.7854) - y * sin(0.7854);
			(*f)->cart[(*f)->i][(*f)->j].y = x * sin(0.7854) + y * cos(0.7854);
			(*f)->j++;
		}
		(*f)->i++;
	}
}

/* .0524 radians = 3 degrees*/ 
void	ft_yrotate(t_env **f)
{
	float	x;
	float	z;

	(*f)->i = 0;
	while ((*f)->i < (*f)->h)
	{
		(*f)->j = 0;
		while ((*f)->j < (*f)->w)
		{
			x = (*f)->cart[(*f)->i][(*f)->j].x;
			z = (*f)->cart[(*f)->i][(*f)->j].z;
			(*f)->cart[(*f)->i][(*f)->j].x = x * cos(0.0524) + z * sin(0.0524);
			(*f)->cart[(*f)->i][(*f)->j].z = -(x * sin(0.0524)) + z * cos(0.0524);
			(*f)->j++;
		}
		(*f)->i++;
	}
}

/* .6982 radians = 40 degrees*/ 
void	ft_xrotate(t_env **f)
{
	float	y;
	float	z;

	(*f)->i = 0;
	while ((*f)->i < (*f)->h)
	{
		(*f)->j = 0;
		while ((*f)->j < (*f)->w)
		{
			y = (*f)->cart[(*f)->i][(*f)->j].y;
			z = (*f)->cart[(*f)->i][(*f)->j].z;
			(*f)->cart[(*f)->i][(*f)->j].y = (y * cos(0.6982) - z * sin(0.6982));
			(*f)->cart[(*f)->i][(*f)->j].z = (y * sin(0.6982) + z * cos(0.6982));
			(*f)->j++;
		}
		(*f)->i++;
	}
}

/* try viewing one rotation at a time to see how each rotation affects the grid */
/* my y rotation doesnt do shit, its there to look pretty */
void	ft_rotate(t_env *f, t_hooks *hooks)
{	
	ft_zrotate(&f);
	ft_xrotate(&f);
	ft_yrotate(&f);	
}
