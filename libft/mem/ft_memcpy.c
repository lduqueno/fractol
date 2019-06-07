/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:46:38 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/05 19:46:40 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned int	i;
	char			*char_src;
	char			*char_dest;

	if (!size)
		return (dest);
	i = 0;
	char_src = (char *)src;
	char_dest = (char *)dest;
	while (i < size)
	{
		*char_dest++ = *char_src++;
		i++;
	}
	return (dest);
}
