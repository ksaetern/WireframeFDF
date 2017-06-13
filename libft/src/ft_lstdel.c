/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:37:13 by ksaetern          #+#    #+#             */
/*   Updated: 2017/01/20 13:43:31 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*list;

	list = *alst;
	while (list != NULL)
	{
		current = list->next;
		del(list->content, list->content_size);
		free(list);
		list = current;
	}
	*alst = NULL;
}
