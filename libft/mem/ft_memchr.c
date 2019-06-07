/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:57:59 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 10:58:01 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t size)
{
	unsigned int	i;
	unsigned char	stop;
	char			*char_src;

	if (!size)
		return (NULL);
	i = 0;
	stop = (unsigned char)c;
	char_src = (char *)src;
	while (i < size)
	{
		if ((unsigned char)*char_src == stop)
			return (char_src);
		char_src += 1;
		i++;
	}
	return (NULL);
}
