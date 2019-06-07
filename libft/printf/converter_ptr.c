/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:21:11 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/14 15:04:09 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*from_ptr(va_list ap, t_context *context)
{
	int					max_zero_pad;
	unsigned long int	i;

	i = (unsigned long int)va_arg(ap, void *);
	max_zero_pad = has_flag(context, "0") && context->pad_count >= context->
			precision ? context->pad_count : context->precision;
	if (has_flag(context, "0"))
		max_zero_pad -= 2;
	if (has_flag(context, ".") && context->precision == 0 && i == 0)
		return (ft_strdup("0x"));
	return (ft_ltoa_base(i, "0123456789abcdef", max_zero_pad < 0 ? 0 :
			max_zero_pad, "0x"));
}
