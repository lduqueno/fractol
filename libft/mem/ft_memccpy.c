/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:12:49 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 09:12:50 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	unsigned int	i;
	unsigned char	stop;
	char			*char_src;
	char			*char_dest;
	unsigned char	next;

	if (!size)
		return (NULL);
	i = 0;
	stop = (unsigned char)c;
	char_src = (char *)src;
	char_dest = (char *)dest;
	while (i < size)
	{
		next = *char_src++;
		*char_dest++ = next;
		if (next == stop)
			return (char_dest);
		i++;
	}
	return (NULL);
}
