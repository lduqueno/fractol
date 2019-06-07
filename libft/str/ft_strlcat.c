/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:07:24 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 13:07:26 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int dest_len;
	unsigned int src_len;
	unsigned int i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size - 1 < dest_len)
		return (src_len + size);
	i = 0;
	while (dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
