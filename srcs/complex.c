/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:51:58 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/21 10:04:42 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

/*
**	Multiply two complex numbers
*/

t_complex	zmultiply(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r * b.r - a.i * b.i;
	result.i = a.i * b.r + a.r * b.i;
	return (result);
}

/*
**	Pow a complex number to n
*/

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

/*
**	Subtract two complex numbers
*/

t_complex	zsubtract(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r - b.r;
	result.i = a.i - b.i;
	return (result);
}

/*
**	Add two complex numbers
*/

t_complex	zadd(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

/*
**	Divide two complex numbers
*/

t_complex	zdivide(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = (a.r * b.r + a.i * b.i) / (b.r * b.r + b.i * b.i);
	result.i = (-a.r * b.i + a.i * b.r) / (b.r * b.r + b.i * b.i);
	return (result);
}
