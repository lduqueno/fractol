/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:53:05 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/18 14:53:06 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int nb2;
	int result;

	result = 0;
	if (nb % 2 == 0)
		nb2 = 2;
	if (nb % 2 == 1)
		nb2 = 3;
	if (nb == 1)
		return (1);
	if (nb <= 0)
		return (0);
	if (nb > 0)
	{
		while (nb2 <= 46340)
		{
			if (nb2 * nb2 == nb)
				return (nb2);
			if (nb2 * nb2 > nb)
				return (nb2 - 1);
			nb2++;
		}
	}
	return (0);
}
