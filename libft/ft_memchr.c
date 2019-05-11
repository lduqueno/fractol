/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:26:49 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/07 10:26:50 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*temp;
	unsigned char		c_cast;
	unsigned int		i;

	i = 0;
	temp = (unsigned char *)s;
	c_cast = (unsigned char)c;
	while (i < n)
	{
		if ((unsigned char)*temp == c_cast)
			return (temp);
		i++;
		temp++;
	}
	return (NULL);
}
