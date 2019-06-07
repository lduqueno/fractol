/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_custom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:50:48 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/18 15:27:31 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy_c(char *dest, const char *src, size_t size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '\0';
	return (dest);
}
