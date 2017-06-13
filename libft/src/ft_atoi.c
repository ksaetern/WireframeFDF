/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 03:21:44 by ksaetern          #+#    #+#             */
/*   Updated: 2017/01/24 18:30:35 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int				nb;
	int				sign;
	unsigned char	*str;

	nb = 0;
	sign = 1;
	str = (unsigned char *)s;
	if (*s == 27)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if ((*str == '-') || (*str <= '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * sign);
}
