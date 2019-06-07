/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:49:45 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/07 14:49:47 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*first;

	if (!lst || !(map = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	first = map;
	while (lst)
	{
		map->next = (*f)(lst);
		map = map->next;
		lst = lst->next;
	}
	return (first->next);
}
