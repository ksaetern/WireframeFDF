/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 06:06:27 by ksaetern          #+#    #+#             */
/*   Updated: 2017/01/21 06:09:23 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char		*r;
	unsigned char	a;
	int				len;

	a = (unsigned char)c;
	r = 0;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == a)
			return ((char *)&str[len]);
		len--;
	}
	return (0);
}
