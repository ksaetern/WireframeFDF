/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:56:37 by ksaetern          #+#    #+#             */
/*   Updated: 2017/01/24 21:33:44 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	char		*str1;
	char		*str2;
	char		*start;
	size_t		i;

	str1 = (char *)big;
	if (!(*big || *lil))
		return ((char*)big);
	while ((*str1 && len > 0) || (len == 0 && *lil == '\0'))
	{
		start = str1;
		str2 = (char *)lil;
		i = len;
		while (*str1 && *str2 && *str1 == *str2 && i > 0)
		{
			str1++;
			str2++;
			i--;
		}
		if (*str2 == '\0')
			return (start);
		len--;
		str1 = start + 1;
	}
	return (NULL);
}
