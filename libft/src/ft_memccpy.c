/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 10:16:18 by ksaetern          #+#    #+#             */
/*   Updated: 2017/01/22 20:36:25 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	k;
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	k = (unsigned char)c;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == k)
			return ((void*)&d[i + 1]);
		i++;
	}
	return (NULL);
}
