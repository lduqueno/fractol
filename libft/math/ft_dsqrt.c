/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:33:17 by lduqueno          #+#    #+#             */
/*   Updated: 2019/01/04 16:24:13 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_dsqrt(int nb)
{
	double	i;
	double	result;

	if (nb == 0 || nb == 1)
		return (nb);
	i = 0.25;
	while (i <= 46340)
	{
		result = i * i;
		if (result == nb)
			return (i);
		else if (result > nb)
			return (i - 0.125);
		i += 0.25;
	}
	return (0);
}
