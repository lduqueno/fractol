/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:19:14 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 11:19:19 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t size)
{
	char			*char_s1;
	char			*char_s2;
	unsigned int	i;

	char_s1 = (char *)s1;
	char_s2 = (char *)s2;
	i = 0;
	while (i < size)
	{
		if (*char_s1 != *char_s2)
			return ((unsigned char)*char_s1 - (unsigned char)*char_s2);
		char_s1++;
		char_s2++;
		i++;
	}
	return (0);
}
