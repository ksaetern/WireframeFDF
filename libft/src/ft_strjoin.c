/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 20:46:31 by ksaetern          #+#    #+#             */
/*   Updated: 2017/01/24 21:07:44 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen((char*)s1) + ft_strlen((char*)s2));
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s1 != '\0')
		new[i++] = *s1++;
	while (*s2 != '\0')
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}
