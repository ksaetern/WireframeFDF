/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 23:01:58 by ksaetern          #+#    #+#             */
/*   Updated: 2017/06/12 23:02:01 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*moves the middle of your grid thats at the 0,0 pixel to the middle of your window */
/*now your shits always centered */
void	ft_translate(t_env **f, t_hooks *hooks)
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
			(*f)->cart[(*f)->i][(*f)->j].x = x + ((*f)->max / 2);
			(*f)->cart[(*f)->i][(*f)->j].y = y + ((*f)->maxside / 2);
			(*f)->j++;
		}
		(*f)->i++;
	}
	printf("translation = [x = %f] [y = %f]\n", ((*f)->max / 2), ((*f)->maxside / 2));
}