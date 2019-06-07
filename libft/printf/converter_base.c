/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:15:03 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/14 17:26:01 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*convert_base(va_list ap, char *base, t_context *context, char *arg)
{
	unsigned long int	i;
	int					max_zero_pad;

	if (has_flag(context, "hh"))
		i = (unsigned char)va_arg(ap, unsigned int);
	else if (has_flag(context, "h"))
		i = (unsigned short)va_arg(ap, unsigned int);
	else if (has_flag(context, "l"))
		i = va_arg(ap, unsigned long int);
	else if (has_flag(context, "ll"))
		i = va_arg(ap, unsigned long long);
	else
		i = va_arg(ap, unsigned int);
	max_zero_pad = has_flag(context, "0") && context->pad_count >= context->
			precision ? context->pad_count : context->precision;
	if (arg && has_flag(context, "0"))
		max_zero_pad -= ft_strlen(arg);
	if (arg && ft_strlen(arg) == 2 && ft_strncmp(arg, "0", 1) == 0 && i == 0)
		arg = NULL;
	if (has_flag(context, ".") && context->precision == 0 && i == 0
		&& !(ft_strequ(base, "01234567") && has_flag(context, "#")))
		return (ft_strdup(""));
	return (ft_ltoa_base(i, base, max_zero_pad < 0 ? 0 : max_zero_pad, arg));
}

char		*from_uint_to_octal(va_list ap, t_context *context)
{
	return (convert_base(ap, "01234567", context, has_flag(context, "#") ?
		"0" : NULL));
}

char		*from_uint_to_uint(va_list ap, t_context *context)
{
	return (convert_base(ap, "0123456789", context, NULL));
}

char		*from_uint_to_uhex_low(va_list ap, t_context *context)
{
	return (convert_base(ap, "0123456789abcdef", context, has_flag(context, "#")
		? "0x" : NULL));
}

char		*from_uint_to_uhex_upp(va_list ap, t_context *context)
{
	return (convert_base(ap, "0123456789ABCDEF", context, has_flag(context, "#")
		? "0X" : NULL));
}
