/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:24:55 by ksaetern          #+#    #+#             */
/*   Updated: 2017/01/23 15:44:22 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *str1;
	const char *str2;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0')
	{
		str1 = big;
		str2 = little;
		while (*str2 != '\0' && *str1 == *str2)
		{
			str1++;
			str2++;
		}
		if (*str2 == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
