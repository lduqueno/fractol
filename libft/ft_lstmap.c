/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:51:15 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/13 15:51:16 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*alst;
	t_list	*tmp;

	if (!(alst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp = alst;
	while (lst)
	{
		alst->next = (*f)(lst);
		alst = alst->next;
		lst = lst->next;
	}
	return (tmp->next);
}
