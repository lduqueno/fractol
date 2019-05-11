/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:48:20 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/06 12:48:21 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int		i;
	char				*memory;

	i = 0;
	memory = (char *)s;
	while (i < n)
	{
		*memory++ = c;
		i++;
	}
	return (s);
}
