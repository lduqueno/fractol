/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_32bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:55:39 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/08 17:10:39 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		reverse_32bits(unsigned int nb)
{
	unsigned int	result;

	result = 0x000000FF & nb;
	result = (result << 8) + ((0x0000FF00 & nb) >> 8);
	result = (result << 8) + ((0x00FF0000 & nb) >> 16);
	result = (result << 8) + ((0xFF000000 & nb) >> 24);
	return (result);
}
