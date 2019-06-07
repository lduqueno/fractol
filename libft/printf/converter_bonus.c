/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:15:33 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/12 22:48:49 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*from_binary(va_list ap, t_context *context)
{
	int		max_zero_pad;

	max_zero_pad = has_flag(context, "0") && context->pad_count >= context->
			precision ? context->pad_count : context->precision;
	return (ft_ltoa_base(va_arg(ap, unsigned long int), "01", max_zero_pad,
			NULL));
}

char		*from_boolean(va_list ap, t_context *context)
{
	int boolean;

	boolean = va_arg(ap, int);
	(void)context;
	if (boolean < 0 || boolean > 1)
		return (ft_strdup("Not a bool"));
	return (ft_strdup(boolean ? "true" : "false"));
}
