/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:50:48 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 12:50:50 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	unsigned int i;

	i = 0;
	while (i < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size)
		dest[i++] = '\0';
	return (dest);
}
