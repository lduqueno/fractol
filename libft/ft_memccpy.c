/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:01:00 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/06 14:01:01 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int		i;
	char				*char_dest;
	char				*char_src;
	unsigned char		char_c;
	unsigned char		next;

	i = 0;
	char_dest = (char *)dest;
	char_src = (char *)src;
	char_c = (unsigned char)c;
	while (i < n)
	{
		next = *char_src++;
		*char_dest++ = next;
		if (next == char_c)
			return (char_dest);
		i++;
	}
	return (NULL);
}
