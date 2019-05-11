/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:27:06 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/06 18:27:07 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int				count;
	unsigned int	i;

	i = 0;
	count = ft_strlen(dest);
	while (src[i] != '\0' && i < n)
	{
		dest[count + i] = src[i];
		i++;
	}
	dest[count + i] = '\0';
	return (dest);
}
