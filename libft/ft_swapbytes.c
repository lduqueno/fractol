/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapbytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:48:59 by rlegan            #+#    #+#             */
/*   Updated: 2019/05/08 17:10:07 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapbytes(uint8_t *bytes, unsigned int n)
{
	uint8_t		tmp;
	uint8_t		i;

	i = 0;
	while (i < n / 2)
	{
		tmp = bytes[n - i - 1];
		bytes[n - i - 1] = bytes[i];
		bytes[i] = tmp;
		++i;
	}
}
