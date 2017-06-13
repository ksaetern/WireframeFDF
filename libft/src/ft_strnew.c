/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:55:18 by ksaetern          #+#    #+#             */
/*   Updated: 2017/01/21 07:58:25 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = ((char *)malloc(sizeof(char) * (size + 1)));
	if (new == NULL)
		return (NULL);
	while (i <= size)
	{
		new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}
