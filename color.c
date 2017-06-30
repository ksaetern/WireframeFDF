/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.fr> 	        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 18:50:24 by ksaetern          #+#    #+#             */
/*   Updated: 2017/06/03 18:50:26 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color3(t_env *fdf, t_bresen *breezy, float distance)
{
	if (distance <= (breezy->range * 0.10))
		return (0x00FF00FF);
	else if (distance <= (breezy->range * 0.20))
		return (0x00FF0000);
	else if (distance <= (breezy->range * 0.30))
		return (0x000099FF);
	else if (distance <= (breezy->range * 0.40))
		return (0x0000FFFF);
	else if (distance <= (breezy->range * 0.50))
		return (0x00FF0033);
	else if (distance <= (breezy->range * 0.60))
		return (0x00FF33FF);
	else if (distance <= (breezy->range * 0.70))
		return (0x0000FFFF);
	else if (distance <= (breezy->range * 0.80))
		return (0x000099FF);
	else if (distance <= (breezy->range * 0.90))
		return (0x00FF0000);
	else if (distance <= breezy->range)
		return (0x00FF00FF);
	return (0x000099FF);
}

int		ft_color2(t_env *fdf, t_bresen *breezy, float distance)
{
	if (distance <= (breezy->range * 0.10))
		return (0x00A725F8);
	else if (distance <= (breezy->range * 0.20))
		return (0x009625F8);
	else if (distance <= (breezy->range * 0.30))
		return (0x00CE25F8);
	else if (distance <= (breezy->range * 0.40))
		return (0x00F825E7);
	else if (distance <= (breezy->range * 0.50))
		return (0x00F825A0);
	else if (distance <= (breezy->range * 0.60))
		return (0x00F83E25);
	else if (distance <= (breezy->range * 0.70))
		return (0x00F86125);
	else if (distance <= (breezy->range * 0.80))
		return (0x00F87D25);
	else if (distance <= (breezy->range * 0.90))
		return (0x00F89D25);
	else if (distance <= breezy->range)
		return (0x00F8C325);
	return (0x006600FF);
}

int		ft_color1(t_env *fdf, t_bresen *breezy, float distance)
{
	if (distance <= (breezy->range * 0.10))
		return (0x00F8C325);
	else if (distance <= (breezy->range * 0.20))
		return (0x00F89D25);
	else if (distance <= (breezy->range * 0.30))
		return (0x00F87D25);
	else if (distance <= (breezy->range * 0.40))
		return (0x00F86125);
	else if (distance <= (breezy->range * 0.50))
		return (0x00F83E25);
	else if (distance <= (breezy->range * 0.60))
		return (0x00F825A0);
	else if (distance <= (breezy->range * 0.70))
		return (0x00F825E7);
	else if (distance <= (breezy->range * 0.80))
		return (0x00CE25F8);
	else if (distance <= (breezy->range * 0.90))
		return (0x009625F8);
	else if (distance <= breezy->range)
		return (0x00A725F8);
	return (0x006600FF);
}


/* I find the distance between point1 and point 2, divide that distance into 10 pieces, when
it goes past each 10% it switches color */
int		ft_color(t_env *fdf, t_bresen *breezy, float distance)
{
	if ((fdf->next_z || fdf->curr_z) > fdf->hmin)
	{
		/*color changes depending on low z value to high z, high to low, 0 to 0, or high to high8*/
		if (fdf->curr_z == fdf->next_z)
			return (ft_color3(fdf, breezy, distance));
		if (fdf->curr_z < fdf->next_z)
			return (ft_color1(fdf, breezy, distance));
		else if (fdf->curr_z > fdf->next_z)
			return (ft_color2(fdf, breezy, distance));
	}
	return (0x006600FF);
}
