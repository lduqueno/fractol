/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:51:46 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/05 18:51:47 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int octet, size_t size)
{
	unsigned int	i;
	char			*memory;

	if (!size)
		return (ptr);
	i = 0;
	memory = (char *)ptr;
	while (i < size)
	{
		*memory++ = octet;
		i++;
	}
	return (ptr);
}
