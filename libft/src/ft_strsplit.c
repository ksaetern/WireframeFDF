/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 05:24:01 by ksaetern          #+#    #+#             */
/*   Updated: 2017/01/23 15:28:07 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s || !c)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * (ft_wordsplit(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			split[i] = (char *)malloc(sizeof(char) * ((ft_until(s, c)) + 1));
			while (ft_until(s, c) > 0)
				split[i][j++] = *s++;
			split[i][j] = '\0';
			i++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}
