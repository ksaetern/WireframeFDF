/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 21:48:08 by ksaetern          #+#    #+#             */
/*   Updated: 2017/01/24 18:02:27 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = ft_strlen(dst) + ft_strlen(src);
	while (dst[i] != '\0' && (size > 0))
	{
		i++;
		size--;
	}
	if (size == 0)
		return (ft_strlen(src) + i);
	while (*src != '\0')
	{
		if (size > 1)
		{
			dst[i] = *src;
			i++;
			size--;
		}
		src++;
	}
	dst[i] = '\0';
	return (k);
}
