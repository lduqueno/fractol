/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:51:58 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/15 15:33:07 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

double		zabs(t_complex complex)
{
	return (sqrt(complex.r * complex.r + complex.i * complex.i));
}

t_complex	zmultiply(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r * b.r - a.i * b.i;
	result.i = a.i * b.r + a.r * b.i;
	return (result);
}

t_complex	zpow(t_complex complex, int n)
{
	int			i;
	t_complex	result;

	result.r = 1;
	result.i = 0;
	i = 0;
	while (i < n)
	{
		result = zmultiply(result, complex);
		i++;
	}
	return (result);
}

t_complex	zsubtract(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r - b.r;
	result.i = a.i - b.i;
	return (result);
}

t_complex	zadd(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

t_complex	zdivide(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = (a.r * b.r + a.i * b.i) / (b.r * b.r + b.i * b.i);
	result.i = (-a.r * b.i + a.i * b.r) / (b.r * b.r + b.i * b.i);
	return (result);
}
