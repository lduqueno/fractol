/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:36:16 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/13 11:36:17 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*content2;
	size_t	size;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		content2 = ft_memalloc(content_size);
		size = content_size;
		ft_memcpy(content2, content, content_size);
		list->content = content2;
		list->content_size = size;
		list->next = NULL;
	}
	if (!(content))
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
	}
	return (list);
}
