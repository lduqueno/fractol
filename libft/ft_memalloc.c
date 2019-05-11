/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:33:42 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/07 16:33:43 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*result;

	if (size)
	{
		if (!(result = (void *)malloc(sizeof(void) * size)))
			return (NULL);
		ft_bzero(result, size);
		return (result);
	}
	return (NULL);
}
