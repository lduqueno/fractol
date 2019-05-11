/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:50:10 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/06 13:50:11 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	char				*memory;
	char				*char_src;

	i = 0;
	memory = (char *)dest;
	char_src = (char *)src;
	while (i < n)
	{
		*memory++ = *char_src++;
		i++;
	}
	return (dest);
}
