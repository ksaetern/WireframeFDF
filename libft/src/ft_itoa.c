/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:38:36 by ksaetern          #+#    #+#             */
/*   Updated: 2017/01/23 14:07:34 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*new;

	i = ft_int_len(n) - 1;
	if (!(new = (char *)malloc(sizeof(char) * (ft_int_len(n) + 1))))
		return (NULL);
	new[i + 1] = '\0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		new[0] = '-';
		n = n * -1;
	}
	while (n > 9)
	{
		new[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	if (n >= 0 && n <= 9)
		new[i] = n + '0';
	return (new);
}
