/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:19:06 by lduqueno          #+#    #+#             */
/*   Updated: 2019/01/04 16:17:29 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_dpow(double nb, int power)
{
	double	result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
