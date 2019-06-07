/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:29:27 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 09:29:29 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned int	i;
	char			*char_src;
	char			*char_dest;
	char			temp[size];

	if (!size || size > 100000000)
		return (dest);
	i = 0;
	char_src = (char *)src;
	char_dest = (char *)dest;
	while (i < size)
		temp[i++] = *char_src++;
	i = 0;
	while (i < size)
		*char_dest++ = temp[i++];
	return (dest);
}
