/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:21:03 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/16 15:08:51 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	fix_round_precision(unsigned int precision)
{
	long double		result;
	unsigned int	i;

	i = 0;
	result = 0.5;
	while (i < precision)
	{
		i++;
		result /= 10.0;
	}
	return (result);
}

static void			check_spec_long(char **result, long double d, int *neg)
{
	t_l_double_num	bits;

	bits.number = d;
	if (bits.s.exponent == 0x7FFF)
	{
		if (bits.s.fraction == 0)
			*result = ft_strdup(bits.s.sign ? "-inf" : "inf");
		else
			*result = ft_strdup("nan");
	}
	else if (bits.s.exponent == 0x0000 && bits.s.sign)
		*neg = 1;
}

static void			check_spec(char **result, double d, int *neg)
{
	t_double_num	bits;

	bits.number = d;
	if (bits.s.exponent == 0x7ff)
	{
		if (bits.s.fraction == 0)
			*result = ft_strdup(bits.s.sign ? "-inf" : "inf");
		else
			*result = ft_strdup("nan");
	}
	else if (bits.s.exponent == 0x000 && bits.s.fraction == 0 && bits.s.sign)
		*neg = 1;
}

static int			prnt_decmls(long double *d, char **r, int p, t_context *c)
{
	int				decimal_count;
	int				print_count;
	char			*temp_free;

	decimal_count = 0;
	write_to_buf(r, (temp_free = ft_ltoa_base((unsigned long long)*d,
		"0123456789", 0, NULL)));
	free(temp_free);
	print_count = ft_strlen(*r);
	if (has_flag(c, "#") || p > 0)
	{
		decimal_count = 1;
		write_to_buf(r, ".");
	}
	if (p < 1)
		return (decimal_count);
	decimal_count = 0;
	while (decimal_count++ < p)
	{
		*d = (*d - (unsigned long long)*d) * 10.0;
		write_to_buf(r, temp_free = ft_ltoa_base((unsigned long long)*d % 10,
			"0123456789", 0, NULL));
		free(temp_free);
	}
	return (1);
}

char				*from_double(va_list ap, t_context *context)
{
	long double		d;
	int				neg;
	char			*result;
	int				precision;
	int				decimal_count;

	result = NULL;
	neg = 0;
	if (has_flag(context, "L"))
		check_spec_long(&result, (d = va_arg(ap, long double)), &neg);
	else
		check_spec(&result, (d = va_arg(ap, double)), &neg);
	neg = (neg == 0 ? d < 0 : neg);
	if (result)
		return (result);
	precision = has_flag(context, ".") ? context->precision : 6;
	if (neg == 1)
		d = -d;
	d += fix_round_precision(precision);
	decimal_count = prnt_decmls(&d, &result, precision, context);
	result = pad_with_zeros(result, context, ft_strlen(result) + decimal_count);
	return (append_flags_double(result, d, context, neg));
}
