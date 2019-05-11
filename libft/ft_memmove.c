/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:00:28 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/06 15:00:29 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while ((int)n > 0)
		{
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	return (dest);
}
