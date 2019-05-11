/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:27:13 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/06 18:27:14 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	if (size == 0)
		return ((size_t)ft_strlen(src));
	while (dest[i] && i < size)
		i++;
	len = i;
	while (src[i - len] && i < size - 1)
	{
		dest[i] = src[i - len];
		i++;
	}
	if (len < size)
		dest[i] = '\0';
	return (len + ft_strlen(src));
}
